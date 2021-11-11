Example of a global int being linked both statically and dynamically. Tried both with extern and inline.

We have a pair `base.h/cpp` which defines an `int`  called `globalInt` with the value `1`. `base.o` is included in a static library `libbase.a` and in a dynamic library `libshared.so`. Then `main` links to both of these.
 

              ┌────────┐
              │  Main  │
        ┌─────┴────────┴─────┐
        │                    │
        │                    │
    ┌───▼──┐           ┌─────▼──┐
    │ Base │◄──────────┤ Shared │
    └──────┘           └────────┘

 

### In the case of `extern int`

If I _declare_ `globalInt` as `extern int globalInt` in `base.h` and _define_ it in `base.cpp`:

- The symbol is `D` (public, in `.data`) in `base.o`
- The symbol is `D` (public, in `.data`) in `libshared.so`
- If I link `main` using `-lshared -lbase`, The symbol is `B` (public, in `.bss`) in `main`
- If I link `main` using `-lbase -lshared`, The symbol is `D` (public, in `.data`) in `main`, with the value `1`
- In both cases, I only get one copy in memory, and it gets the value `1`. I'm not sure if this is to be relied on, especially when `main` has it in `.bs`s and `libshared.s`o has it as `1`. Is it just luck that makes sure it's `1` and not `0`? In any case it's probably not a good idea to have the variable defined in two places when it's not unique/weak. I think I would have preferred a linker error here.
- At least we only have one definition of it in the running process, so there is no ODR violation for it when we get to that point. 

However, if I do -fvisibility=hidden when I build base.o (or if I do --exclude-libs libbase.a when I make libshared.so):

- The symbol is `D` (public, in `.data`) in `base.o`
- The symbol is `d` (private, in `.data`) in `libshared.so`, with the value `1`
- The symbol is `D` (public, in `.data`) in `main`, with the value `1`
- The loader is unable to fix this, and we now have two copies in memory. They both have the value `1`, but writes to one will only affect that one copy. So this is definitely bad, and it's an ODR violation at run time.

 
### In the case of inline

If I instead define `globalInt` as `inline int globalInt=1` directly in `base.h`:
	
- The symbol is `u` (unique global symbol which the loader ensures the uniqueness of) in all of `base.o`, `libshared.so`, and `main`. It's in the `.data` section with value `1`.
- The symbol is present both in the normal and the dynamic symbol tables for `libshared.so`
- I only get one copy in memory, guaranteed by the loader, this is what we want!

However, if I do -fvisibility=hidden when I build base.o

- The symbol is `u` (unique global symobl) in `base.o` and `main`, but `d` (private, in `.data`) in `libshared.so`.
- The symbol is only present in the normal symbol table, but not in the dynamic symbol table for `libshared.so`.
- Now that the symbol isn't `u` everywhere, the loader doesn't make it unique, and we get two copies again, and an ODR violation.
- Linking order of `-lbase and -lshared` does not matter in this case.
