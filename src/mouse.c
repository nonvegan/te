#include "./mouse.h"
#include "./tile_glyph.h"
#include <stdlib.h>
#include <math.h>

void mouse_click_move_cursor_tgr(Vec2f mouse_pos, Vec2f window_size, Vec2f camera_pos, Editor *editor)
{

    const Vec2f click_pos =
        vec2f_add(mouse_pos, vec2f_sub(vec2f(camera_pos.x, -camera_pos.y + FONT_CHAR_HEIGHT * FONT_SCALE),
                                                       vec2f_mul(window_size, vec2fs(0.5f))));

    if(click_pos.x > 0.0f && click_pos.y > 0.0f) {
        editor->cursor_col = (size_t) floorf(click_pos.x / ((float) FONT_CHAR_WIDTH * FONT_SCALE));
        editor->cursor_row = (size_t) floorf(click_pos.y / ((float) FONT_CHAR_HEIGHT * FONT_SCALE));
    }

}

void mouse_click_move_cursor_fgr(Vec2f mouse_pos, Vec2f window_size, Vec2f camera_pos, Editor *editor, Free_Glyph_Buffer *fgb, int font_size) 
{
    const Vec2f click_pos =
        vec2f_add(mouse_pos, vec2f_sub(vec2f(camera_pos.x, -camera_pos.y + (float) font_size),
                                       vec2f_mul(window_size, vec2fs(0.5f))));

    if(click_pos.x > 0.0f && click_pos.y > 0.0f) {
        editor->cursor_row = (size_t) floorf(click_pos.y / (float) font_size);

        if(!editor->size || editor->cursor_row >= editor->size) {
            editor->cursor_col = 0;
        } else {
            Line *line = editor->lines + editor->cursor_row;
            float sum_ax_line = 0.0f;

            for(size_t i = 0; i < line->size; i++) {
                float ax_char = fgb->metrics[(int) line->chars[i]].ax;

                if(sum_ax_line + ax_char / 2.0f > click_pos.x) {
                    editor->cursor_col = i;
                    break;
                } 
                if(i + 1 == line->size) {
                    editor->cursor_col = line->size;
                }

                sum_ax_line += ax_char;
            }
        }
    }
}
