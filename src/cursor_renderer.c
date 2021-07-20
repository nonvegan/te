#include <stdlib.h>
#include "./gl_extra.h"
#include "./cursor_renderer.h"

void cursor_renderer_init(Cursor_Renderer *cr,
                          const char *vert_file_path,
                          const char *frag_file_path)
{
    // Init Shaders
    {
        GLuint shaders[3] = {0};

        if (!compile_shader_file(vert_file_path, GL_VERTEX_SHADER, &shaders[0])) {
            exit(1);
        }
        if (!compile_shader_file(frag_file_path, GL_FRAGMENT_SHADER, &shaders[1])) {
            exit(1);
        }
        if (!compile_shader_file("./shaders/camera.vert", GL_VERTEX_SHADER, &shaders[2])) {
            exit(1);
        }

        cr->program = glCreateProgram();
        attach_shaders_to_program(shaders, sizeof(shaders) / sizeof(shaders[0]), cr->program);
        if (!link_program(cr->program, __FILE__, __LINE__)) {
            exit(1);
        }

        glUseProgram(cr->program);
        get_uniform_location(cr->program, cr->uniforms);
    }
}

void cursor_renderer_use(const Cursor_Renderer *cr)
{
    glUseProgram(cr->program);
}

void cursor_renderer_move_to(const Cursor_Renderer *cr, Vec2f pos)
{
    glUniform2f(cr->uniforms[UNIFORM_SLOT_CURSOR_POS], pos.x, pos.y);
}

void cursor_renderer_draw()
{
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
}
