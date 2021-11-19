(Read `link-twice` first)
In this experiment We've replaced the global `globalInt` with a global `struct NonTrivial` which just prints "Constructed" in its constructor and does nothing else.
 

### In the case of extern

If I declare `nonTrivial` as `extern NonTrivial nonTrivial` in `base.h` and then define it in `base.cpp`:
	
- The symbol is now `B` (public, in `.bss`) in both `base.o`, `libshared.s`o, and `main`, since it's initialized by a constructor rather than by an `int`.
- There is always just one instance in memory, probably because the symbols are public everywhere and the loader happens to only load one. But I'm not sure if this is reliable.
- If I link main using `-lshared -lbase`, I see "Constructed" printed once. 
- If I link main using `-lbase -lshared`, I see "Constructed" printed twice, even if there's just one copy in memory. So it's constructed twice in the same place.
- One can see why that is by doing `objdump -D main`, and see that there's a `__static_initialization_and_destruction_0` which constructs `nonTrivial` only in the case where one links to `base` first.
- The reason that we only get one construction when we link to `shared` first is probably that the linker has then already resolved this when it gets around to `-lbase`, and doesn't include the constructor since it knows that the `.so` will handle it.

However, if I do `-fvisibility=hidden` when I build `base.o`:
	
- The symbol is now `B` (public, in `.bss`) in `base.o` and `main`, but `b` (private, in `.bss`) in `libshared.so`.
- No matter the linking order I get two copies in memory, probably because there is no `nonTrivial` in the dynamic symbol table for `libshared.so` and the loader is unable to fix the uniqueness. This is an ODR violation.
- No matter the linking order, "Constructed" is printed twice. Both `main` and `libshared.so` include calls to the constructor.

### In the case of inline

If I instead define `nonTrivial` as `inline NonTrivial nonTrivial` directly in `base.h`:

- The symobl is `u` (unique global symbol which the loader ensures the uniqueness of) in all of `base.o`, `libshared.so` and `main`. 
- There is only one copy in memory, guaranteed by the loader, this is what we want!
- The `__static_initialization_and_destruction_0` which calls the `NonTrivial` constructor is present both in `main` and `libshared.so`. Yet it's still only constructed once. There's a guard variable for `nonTrivial` which I assume is responsible for this.
- Linking order of `-lbase` and `-lshared` does not matter.

However, if I do `-fvisibility=hidden` when I build `base.o`:
	
- The symobl is `u` (unique global symobl) in `base.o` and `main`, but `b` (private, in `.bss`) in `libshared.so`
- Now that the symbol isn't `u` everywhere, I get two copies in memory, and see the constructor running twice
- Linking order does not matter

So `inline` and public symbols is again the way to go. And the main takeaway is that it is not enough to just check that you only get one copy in memory. You can still have bugs with just one copy, when that copy is constructed twice.
