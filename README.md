# Qwt3D-Examples

All of these examples are from https://github.com/sintegrial/qwtplot3d !!! The code in `examples` folder is almost entirely unchanged.
All I did was compile them to a single widget with tabs so I would have easier time looking up the features I needed.

# Setup for msys2

* Setup libraries:
  * Open msys2 terminal
  * Run `pacman -S mingw-w64-x86_64-vulkan-devel`
* Setup environment:
  * Add system environment variable `VULKAN_SDK`
  * Set VULKAN_SDK value to mingw64 folder path. For example: `c:\msys64\mingw64`
  * Open `[mingw64 folder path]\share\qt5\mkspecs\common\windows-vulkan.conf`
  * Optional: Change `load(windows_vulkan_sdk)` to `load(win32/windows_vulkan_sdk)` https://forum.qt.io/topic/107833/cannot-find-feature-windows_vulkan_sdk/9

# Screenshot
![Screenshot](/screenshot.png)
