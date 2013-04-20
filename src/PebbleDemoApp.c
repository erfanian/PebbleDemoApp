#include "pebble_os.h"
#include "pebble_app.h"
#include "pebble_fonts.h"


#define MY_UUID { 0x60, 0x62, 0xDE, 0x83, 0x46, 0x49, 0x46, 0xBF, 0x9A, 0xD1, 0xE5, 0xE8, 0xAB, 0x1F, 0xA3, 0xD0 }
PBL_APP_INFO(MY_UUID,
             "Demo App", "Eric Erfanian",
             1, 0, /* App version */
             RESOURCE_ID_IMAGE_MENU_ICON,
             APP_INFO_STANDARD_APP);

Window window;

Layer layer;

void update_layer_callback(Layer *me, GContext* ctx) {
  (void)me;

  graphics_context_set_text_color(ctx, GColorBlack);

  graphics_text_draw(ctx,
		     "Hello.",
		     fonts_get_system_font(FONT_KEY_DROID_SERIF_28_BOLD),
		     GRect(5, 5, 200, 200),
		     GTextOverflowModeWordWrap,
		     GTextAlignmentLeft,
		     NULL);
}

void handle_init(AppContextRef ctx) {
  (void)ctx;

  window_init(&window, "Window Name");
  window_stack_push(&window, true /* Animated */);
  
  layer_init(&layer, window.layer.frame);
  layer.update_proc = update_layer_callback;
  layer_add_child(&window.layer, &layer);
}


void pbl_main(void *params) {
  PebbleAppHandlers handlers = {
    .init_handler = &handle_init
  };
  app_event_loop(params, &handlers);
}
