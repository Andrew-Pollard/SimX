# SimX

An interface specification for time-stepping models within a simulation. The
design is inspired by [OpenGL
extensions](https://www.khronos.org/opengl/wiki/OpenGL_Extension), [Wayland
protocols](https://gitlab.freedesktop.org/wayland/wayland-protocols/) and the
[Component pattern](https://gameprogrammingpatterns.com/component.html).

The style of the interface is inspired by [GLFW](https://www.glfw.org/).


## SimX Core Interface
This repository contains the SimX Core Interface which all compliant models must
implement in its entirety. This interface contains the minimal functionality
required for an implementation to describe itself and the extension interfaces
it supports.


## Extension Interfaces
Extension interfaces are additions to the SimX Core Interface which expose
functionality which only a subset of models support.


## Versioning
The SimX Core Interface uses [Semantic Versioning](https://semver.org/).

All versions of the SimX Core Interface are guaranteed to contain the following
function that can be used to determine which version of the SimX Core Interface
a dynamic library (a `*.dll`/`*.so`/etc. file) implements:
```c
int simx_get_api_version_number(int* major, int* minor, int* patch);
```
`simx_get_api_version_number()` returns `0` on success and non-zero if an error
occurs.

Additionally all versions of the SimX Core Interface are guaranteed to contain
the following function that can be used to get the full Semantic Version
including any additional labels it may contain:
```c
const char* simx_get_api_version();
```
`simx_get_api_version()` returns a null-terminated UTF-8 string.

> Note that this is the version information of the SimX Core Interface the
> dynamic library implements - not the version information of the
> implementation.


## Documentation
API reference is available on [GitHub Pages](https://andrew-pollard.github.io/SimX/).


## Tasks
- [X] Create a README.
- [X] Add [Doxygen](https://www.doxygen.nl/) comments.
- [ ] Create a reference implementation.
    - [ ] Set up git submodules.
    - [ ] Set up cmake.
    - [ ] Set up Github actions.
- [ ] Create a C# wrapper.


## Useful Tools
- [Code Spell Checker](https://marketplace.visualstudio.com/items/?itemName=streetsidesoftware.code-spell-checker)
- [Markdown Checkboxes](https://marketplace.visualstudio.com/items/?itemName=bierner.markdown-checkbox)
- [Markdown Emoji](https://marketplace.visualstudio.com/items/?itemName=bierner.markdown-emoji)
- [Rewrap Revived](https://marketplace.visualstudio.com/items?itemName=dnut.rewrap-revived)
