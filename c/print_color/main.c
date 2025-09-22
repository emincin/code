#include <stdio.h>

#define RESET_STYLE "\033[0m"

void reset_style() {
  printf(RESET_STYLE);
}

void set_fg_idx(int idx) {
  printf("\033[38;5;%dm", idx);
}

void set_fg_rgb(int r, int g, int b) {
  printf("\033[38;2;%d;%d;%dm", r, g, b);
}

void set_bg_idx(int idx) {
  printf("\033[48;5;%dm", idx);
}

void set_bg_rgb(int r, int g, int b) {
  printf("\033[48;2;%d;%d;%dm", r, g, b);
}

void set_colors_idx(int fg_idx, int bg_idx) {
  printf("\033[38;5;%d;48;5;%dm", fg_idx, bg_idx);
}

void set_colors_rgb(int fg_r, int fg_g, int fg_b, int bg_r, int bg_g, int bg_b) {
  printf("\033[38;2;%d;%d;%d;48;2;%d;%d;%dm", fg_r, fg_g, fg_b, bg_r, bg_g, bg_b);
}

void print_fg_idx(const char* s, int idx) {
  printf("\033[38;5;%dm%s" RESET_STYLE, idx, s);
}

void print_fg_rgb(const char* s, int r, int g, int b) {
  printf("\033[38;2;%d;%d;%dm%s" RESET_STYLE, r, g, b, s);
}

void print_bg_idx(const char* s, int idx) {
  printf("\033[48;5;%dm%s" RESET_STYLE, idx, s);
}

void print_bg_rgb(const char* s, int r, int g, int b) {
  printf("\033[48;2;%d;%d;%dm%s" RESET_STYLE, r, g, b, s);
}

void print_colors_idx(const char* s, int fg_idx, int bg_idx) {
  printf("\033[38;5;%d;48;5;%dm%s" RESET_STYLE, fg_idx, bg_idx, s);
}

void print_colors_rgb(const char* s, int fg_r, int fg_g, int fg_b, int bg_r, int bg_g, int bg_b) {
  printf("\033[38;2;%d;%d;%d;48;2;%d;%d;%dm%s" RESET_STYLE, fg_r, fg_g, fg_b, bg_r, bg_g, bg_b, s);
}

int main(int argc, char** argv) {
  return 0;
}
