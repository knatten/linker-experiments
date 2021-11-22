In this example we have a static local `static int StaticInt` inside a function `getStatic` which is linked both statically and dynamically.

I then try compiling with and without `-fvisibility=hidden`, and with both orders of `-lbase` and `-lshared`.

With hidden visibility, this does not work. We get two different copies used in the running process, depending on whether the function is called via the shared library or not.

With default visibility, this works. We always get only one copy used in the running process. If we link with shared first, we get one copy in `libShared.so` only, if we link with base first, we get one in `libShared.so` and one in `main`, but only one is used in the running process.

Here's a summary for `staticInt`, where I list the symbol type as well as the number of different answers to `&staticInt` during runtime:

| Visibility | First  | `libShared.so` | `main` | Used in program  |
|------------|--------|----------------|--------|------------------|
| default    | base   | d              | d      | 1                |
| default    | shared | d              |        | 1                |
| hidden     | base   | d              | d      | 2                |
| hidden     | shared | d              | d      | 2                |

How does that happen? Symbol visibility of `staticInt` does not explain it. For normal global variables, things like these are normally dependent on the symbol visibility of the global. With default visibility (global object in `nm`), the dynamic linker is able to resolve all references to that name to the same address. With hidden visibility (local object in `nm`), it is not, and we get duplicates. For this example though, `staticInt` always has hidden visibility, so that does not explain it.

What does explain it though is the visibility of `getStatic()` itself. In all the cases above, `staticInt` is resolved directly without an indirection through GOT, so the dynamic linker has no way to even fix this. But if we always use the same instance of `getStatic()` itself, it will always resolve to the correct `staticInt`!

Here is that same table again, but for `getStatic`:

| Visibility | First  | `libShared.so` | `main` | Used in program  |
|------------|--------|----------------|--------|------------------|
| default    | base   | T              | T      | 1                |
| default    | shared | T              | U      | 1                |
| hidden     | base   | t              | t      | 2                |
| hidden     | shared | t              | t      | 2                |

So we can see that in the cases with default visibility, there's only one version of `getStatic` used during runtime, even if we have two copies in the binaries if we link to base first. And with hidden visibility, we always both get and use two different copies of `getStatic`.
