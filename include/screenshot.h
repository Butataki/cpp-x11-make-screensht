#ifndef SCREENSHOT_H_INCLUDED_
#define SCREENSHOT_H_INCLUDED_
#include <vector>
#include <string>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/X.h>
using namespace std;

class X11Screenshot {
    public:
        X11Screenshot(XImage * image, int new_width=0, int new_height=0, string scale_type="linear");
        bool save_to_png(const char * path);
        bool save_to_jpeg(const char * path, int quality);
        int get_width(void);
        int get_height(void);

    private:
        int width = 0;
        int height = 0;
        vector<vector<unsigned char>> image_data = vector<vector<unsigned char>>();
        vector<vector<unsigned char>> process_original(XImage * image);
        vector<vector<unsigned char>> process_scale_linear(XImage * image, int new_width=0, int new_height=0);
        vector<vector<unsigned char>> process_scale_bilinear(XImage * image, int new_width=0, int new_height=0);
};

#endif
