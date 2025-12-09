/**
 * Assume that you have complete and correct implementations of PNG and RGBAPixel from the Intro Lab available to you.
 * For reference, you can see the key parts of PNG.h and RGBAPixel.h below.
 * We're working on a "striping" transition animation for images, where the image changes towards white in horizontal
 * stripes.
 * As a first step on the way, we're creating a function stripe that takes an image and modifies every fourth horizontal
 * row of the image starting with the row where y = 3 so that each pixel in the row has each of its red, green, and blue
 * channels set to be 21 units larger.
 * Complete the function stripe below so that it implements this behaviour.
 * Notes:
 * RGB values must be in the range [0, 255]. A value less than 0 should be clamped to 0. A value more than 255 should
 * likewise be clamped to 255.
 * Substantial partial credit is available for applying the correct change requested above to all pixels in the image.
 * So, start with that!
*/

#include <cmath>

#include "PNG.h"
#include "RGBAPixel.h"
#include "stripe.h"

/**** NO OTHER INCLUDES ARE ALLOWED ****/

// Here are the key contents of PNG.h
class PNG {
  public:
    /** Gets a pointer to the pixel at the given coordinates.
      * (0,0) is the upper left corner. */
    RGBAPixel* getPixel(unsigned int x, unsigned int y);

    /** @return Width of the image. */
    unsigned int width() const;

    /** @return Height of the image. */
    unsigned int height() const;

    /** Resizes the image to the given coordinates. Crops if needed.
      * @param newWidth New width of the image.
      * @param newHeight New height of the image. */
    void resize(unsigned int newWidth, unsigned int newHeight);

    /** Additional elements like constructor, assigment, etc. left out.
      * Your code should not rely on these elements! */
};

// Here are the key contents of RGBAPixel.h
class RGBAPixel {
  public:
    unsigned char r; // Red: In the range [0, 255].
    unsigned char g; // Green: In the range [0, 255].
    unsigned char b; // Blue: In the range [0, 255].
    double a; // Alpha: In the range [0, 1].

    /** Construct a pixel with maximum r, g, b and a. */
    RGBAPixel();

    /** Construct a pixel with the given r, g, and b values and a set to 1. 
      * Does not check/ensure the ranges specified above. */
    RGBAPixel(unsigned char red, unsigned char green, unsigned char blue);

    /** Construct a pixel with the given r, g, b, and a values.
      * Does not check/ensure the ranges specified above. */
    RGBAPixel(unsigned char red, unsigned char green, unsigned char blue, double alpha);
};

/**
 *  "Stripes" image and returns the result.
 *  (For examlet brevity: see above for "striping" definition!)
**/
PNG stripe(PNG image) {
    // TODO: complete this function!
    for (unsigned int i = 0; i < image.width(); i++) {
        for (unsigned int j = 3; j < image.height(); j+=4) {
            RGBAPixel* p = image.getPixel(i, j);
            if (p->r > 234) {
                p->r = 255;
            } else {
                p->r += 21;
            }
            
            if (p->g > 234) {
                p->g = 255;
            } else {
                p->g += 21;
            }
            
            if (p->b > 234) {
                p->b = 255;
            } else {
                p->b += 21;
            }
        }
    }
    return image;
}
