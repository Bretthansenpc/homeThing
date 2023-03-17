#pragma once

#include <string>
#include "esphome/components/display/display_buffer.h"
#include "homeThingColorPalette.h"

namespace esphome {
namespace homething_menu_base {

class HomeThingMenuDisplayState {
 public:
  display::Font* get_font_small() { return font_small_; }
  void set_font_small(display::Font* font_small) { font_small_ = font_small; }

  display::Font* get_font_medium() { return font_medium_; }
  void set_font_medium(display::Font* font_medium) {
    font_medium_ = font_medium;
  }

  display::Font* get_font_large() { return font_large_; }
  void set_font_large(display::Font* font_large) { font_large_ = font_large; }

  display::Font* get_font_large_heavy() { return font_large_heavy_; }
  void set_font_large_heavy(display::Font* font_large_heavy) {
    font_large_heavy_ = font_large_heavy;
  }

  display::Font* get_font_material_large() { return font_material_large_; }
  void set_font_material_large(display::Font* font_material_large) {
    font_material_large_ = font_material_large;
  }

  display::Font* get_font_material_small() { return font_material_small_; }
  void set_font_material_small(display::Font* font_material_small) {
    font_material_small_ = font_material_small;
  }

  display::Font* get_font_logo() { return font_logo_; }
  void set_font_logo(display::Font* font_logo) { font_logo_ = font_logo; }

  bool get_draw_now_playing_bottom_menu() { return draw_now_playing_menu_; }
  void set_draw_now_playing_bottom_menu(bool draw_now_playing_menu) {
    draw_now_playing_menu_ = draw_now_playing_menu;
  }

  int get_header_height() { return header_height_; }
  void set_header_height(int header_height) { header_height_ = header_height; }
  int get_margin_size() { return margin_size_; }
  void set_margin_size(int margin_size) { margin_size_ = margin_size; }
  int get_bottom_bar_margin() { return bottom_bar_margin_; }
  void set_bottom_bar_margin(int bottom_bar_margin) {
    bottom_bar_margin_ = bottom_bar_margin;
  }
  int get_slider_margin_size() { return slider_margin_size_; }
  void set_slider_margin_size(int slider_margin_size) {
    slider_margin_size_ = slider_margin_size;
  }
  int get_icon_size() { return icon_size_; }
  void set_icon_size(int icon_size) { icon_size_ = icon_size; }
  int get_scroll_bar_width() { return scroll_bar_width_; }
  void set_scroll_bar_width(int scroll_bar_width) {
    scroll_bar_width_ = scroll_bar_width;
  }
  int get_boot_logo_size() { return boot_logo_size_; }
  void set_boot_logo_size(int boot_logo_size) {
    boot_logo_size_ = boot_logo_size;
  }
  int get_now_playing_max_lines() { return now_playing_max_lines_; }
  void set_now_playing_max_lines(int now_playing_max_lines) {
    now_playing_max_lines_ = now_playing_max_lines;
  }
  float get_font_size_width_ratio() { return font_size_width_ratio_; }
  void set_font_size_width_ratio(float font_size_width_ratio) {
    font_size_width_ratio_ = font_size_width_ratio;
  }
  bool get_draw_shuffle_disabled() { return draw_shuffle_disabled_; }
  void set_draw_shuffle_disabled(bool draw_shuffle_disabled) {
    draw_shuffle_disabled_ = draw_shuffle_disabled;
  }
  bool get_draw_header_time() { return draw_header_time_; }
  void set_draw_header_time(bool draw_header_time) {
    draw_header_time_ = draw_header_time;
  }
  bool get_draw_battery_level() { return draw_battery_level_; }
  void set_draw_battery_level(bool draw_battery_level) {
    draw_battery_level_ = draw_battery_level;
  }
  bool get_dark_mode() { return dark_mode_; }
  void set_dark_mode(bool dark_mode) { dark_mode_ = dark_mode; }
  bool get_draw_volume_level() { return draw_volume_level_; }
  void set_draw_volume_level(bool draw_volume_level) {
    draw_volume_level_ = draw_volume_level;
  }
  std::string get_boot_device_name() { return boot_device_name_; }
  void set_boot_device_name(std::string boot_device_name) {
    boot_device_name_ = boot_device_name;
  }

  int getBottomBarYPosition(bool spaceForMenu, int display_height) {
    int barHeight = font_small_->get_height();
    int menuSpace = spaceForMenu && get_draw_now_playing_bottom_menu()
                        ? font_large_->get_height()
                        : 0;
    int yPos = display_height - margin_size_ - menuSpace - bottom_bar_margin_ -
               barHeight;
    return yPos;
  }

  HomeThingColorPalette* get_color_palette() { return color_palette_; }
  void set_color_palette(HomeThingColorPalette* color_palette) {
    color_palette_ = color_palette;
  }

 private:
  HomeThingColorPalette* color_palette_;
  display::Font* font_small_{nullptr};
  display::Font* font_medium_{nullptr};
  display::Font* font_large_{nullptr};
  display::Font* font_large_heavy_{nullptr};
  display::Font* font_material_large_{nullptr};
  display::Font* font_material_small_{nullptr};
  display::Font* font_logo_{nullptr};
  int header_height_;
  int margin_size_;
  int bottom_bar_margin_;
  int slider_margin_size_;
  int icon_size_;
  int scroll_bar_width_;
  int boot_logo_size_;
  int now_playing_max_lines_;
  float font_size_width_ratio_;
  bool draw_shuffle_disabled_;
  bool draw_header_time_;
  bool draw_battery_level_;
  bool dark_mode_;
  bool draw_volume_level_;
  bool draw_now_playing_menu_;
  std::string boot_device_name_ = "homeThing";
};
}  // namespace homething_menu_base
}  // namespace esphome
