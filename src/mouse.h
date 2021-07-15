#ifndef MOUSE_H_
#define MOUSE_H_

#include <stdio.h> 
#include "./editor.h"
#include "./la.h"
#include "./free_glyph.h"

void mouse_click_move_cursor_fgr(Vec2f mouse_pos, Vec2f window_size, Vec2f camera_pos, Editor *editor, Free_Glyph_Buffer *fgb, int font_size);

void mouse_click_move_cursor_tgr(Vec2f mouse_pos, Vec2f window_size, Vec2f camera_pos, Editor *editor);

#endif // MOUSE_H_
