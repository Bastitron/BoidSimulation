![Boid Simulation by Bastitron](gh_assets/title.png)

A simple Boid Simulation application that replicates the movement patterns observed in flocking birds.

## Features

- Gui for controlling rules and so on
- [Google code style guide](https://google.github.io/styleguide/cppguide.html)

## Build instructions

A Win64 build is provided under releases.

```bash
  ./vcpkg install imgui[sdl2-renderer-binding]
  ./vcpkg install sdl2
  ./vcpkg install fmt
```

### Dependencies

**VCPKG**
- [SDL2](https://vcpkg.link/ports/sdl2)
- [ImGUI](https://vcpkg.link/ports/imgui)
- [fmt](https://vcpkg.io/en/package/fmt)


