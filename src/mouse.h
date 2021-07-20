#ifndef MOUSE_H_
#define MOUSE_H_

#include <stdio.h> 
#include "./editor.h"
#include "./la.h"
#include "./free_glyph.h"

void mouse_click_move_cursor(Vec2f mouse_pos, Vec2f window_size, Vec2f camera_pos, float scamera_scale, Editor *editor, Free_Glyph_Buffer *fgb, int font_size);

#endif // MOUSE_H_
