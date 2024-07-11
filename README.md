# CAB401-M1-Mac-OpenMP
Instructions for setting up OpenMP on an ARM based Mac. Should work for Intel based chips but haven't tested it.

## Requirements
1. You need homebrew installed

## Install brew packages
2. `brew install wget`: `wget` is a package for installing internet files
3. `brew install llvm`: `llvm` is a compiler infrastructure

## Create a new XCode Application 
4. Open XCode and create a new `Command Line Tool` App for macOS. This should work for any type of application, but you only need the command line for CAB401.
5. Name it whatever you want and choose `C++` as the language
6. Save it to whatever folder you want.

## Change Build Settings
7. It should already open the `.xcodeproj` (app file), if it hasn't double click the project file to open it (it's the blue one).
8. Navigate to **Build Settings**, then click the **+** symbol to **Add User-Defined Setting**
<img width="857" alt="image" src="https://github.com/ShridharThorat/CAB401-M1-Mac-OpenMP/assets/89955832/130f8ebf-ccff-4d0c-a92e-cf5e113bd5ae">

10. Name it `CC` and it should link to the something like `usr/local/opt/llvm/bin/clang`. This might be `/opt/homebrew/Cellar/llvm/18.1.8/bin/clang ` on your computer. To determine where it is, try find your homebrew folder and go into the cellar folder (where your packages are) and find llvm there.
11. Click **All** as in the picture before to show all the settings
12. Disable the **Enable Modules (C and Objective-C)** setting
13. Next you need to add the `llvm/lib` path to the **Library Search Paths** setting. You should have already found the location of the llvm directory so just copy the `lib` folder as pathname in Finder and paste it in Xcode. The actual path would be similar to `/opt/homebrew/Cellar/llvm/18.1.8/lib`
14. Next you need to add the `include` folder to the **Header Search Paths**. It's similar to `/opt/homebrew/Cellar/llvm/18.1.8/lib/clang/18/include`. You might have a different version so 18 may be 13, 14 or some other number.
15. In the **Other C Flags** setting, include `-fopenmp`. This will enable OpenMP. Without it your program will always run sequentially. You can add any flags you'd like here as well.
16. Disable the **Enable Index-While-Building Functionality** setting

## Change Build Phases
17. **Build Phases** should be next to **Build Settings** on the top of your screen, click on it. 
18. Press **++** in the **Link Binary With Libraries**. This should have 0 items at the moment **(0 items)**.
19. In the directory `usr/local/lib` or `opt/Homebrew/lib` folder, you want to find the `libomp.dylib` file. If it isn't here, it might be `/opt/homebrew/Cellar/llvm/18.1.8/lib/libomp.dylib` or `/opt/homebrew/Cellar/libomp/16.0.6/lib/libomp.dylib`. Navigage to `libomp` in the `Cellar` and go from there.

## Test if it works.
21. For simplicity, try the following in the your main.cpp function. Change 5 to whatever number of threads you want.
  ```
  #include <stdio.h>
  #include <omp.h>
  
  int main(int argc, char** argv){
      #pragma omp parallel num_threads(5)
      {
          printf("Hello from process: %d\n", omp_get_thread_num());
      }
      return 0;
  }

  ```


