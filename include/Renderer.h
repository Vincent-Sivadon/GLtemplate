#pragma once

#include "Cube.h"
#include "Scene.h"

namespace GLhf
{

    class Renderer
    {
    private:

    public:
        Renderer() {}
        
        void Create(Scene& scene)
        {
            glm::mat4 projection = glm::perspective(glm::radians(45.0f), 1800.0f / 950.0f, 0.1f, 400.0f);
            for (Cube& cube : scene.cubes_)
                cube.SetProjection(projection);
            for (InstanceCube& instance_cube : scene.instance_cubes_)
                instance_cube.SetProjection(projection);
        }

        void Draw(Cube& cube, glm::mat4& current_view_matrix, glm::vec3& camera_pos)
        {
            cube.SetView(current_view_matrix);
            cube.SetCameraPos(camera_pos);
            cube.Bind();
            glDrawElements(GL_TRIANGLES, cube.ElementsBufferSize(), GL_UNSIGNED_INT, 0);
        }

        void DrawInstance(InstanceCube& instance_cube, glm::mat4& current_view_matrix, glm::vec3& camera_pos)
        {
            instance_cube.SetView(current_view_matrix);
            instance_cube.SetCameraPos(camera_pos);
            instance_cube.Bind();
            glDrawElementsInstanced(
                GL_TRIANGLES,
                instance_cube.ElementsBufferSize(),
                GL_UNSIGNED_INT,
                0,
                instance_cube.nb_of_instances_);

        }

        void Clear()
        {
            glClearColor(0.01f, 0.01f, 0.01f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        }
    };


}