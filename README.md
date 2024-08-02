If you create a new project and want to use the codes here, you need to perform several processes:
1. First you need to instal the OpenGL library. If you are using devC++ do it by watching this video - [https://www.youtube.com/watch?v=8Qkpaewj-7Y&t=308s]
2. Then in Project/Project Options/Parameters/Linker type the following:
   -lopengl32
   -lfreeglut
   -lglu32

![linker](https://github.com/user-attachments/assets/28ec3fbb-e244-4e3f-8092-0b32c98247eb)

This is how the project will look when working:

![solar_system](https://github.com/user-attachments/assets/1de0d26f-2a45-4a64-8f2d-4fb16027b0ba)
