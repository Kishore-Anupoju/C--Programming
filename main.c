#include <stdio.h>
#include <stdint.h>

#pragma pack(push,1)

typedef struct {
    uint16_t type;
    uint32_t size;
    uint16_t reserved1;
    uint16_t reserved2;
    uint32_t offset;
} BMPHeader;

typedef struct {
    uint32_t size;
    int32_t width;
    int32_t height;
    uint16_t planes;
    uint16_t bitCount;
    uint32_t compression;
    uint32_t sizeImage;
    int32_t xPelsPerMeter;
    int32_t yPelsPerMeter;
    uint32_t clrUsed;
    uint32_t clrImportant;
} DIBHeader;

#pragma pack(pop)

int main() {
    const int W = 200;
    const int H = 200;
    int rowPadded = (W * 3 + 3) & (~3);
    int dataSize = rowPadded * H;

    BMPHeader bmp = {
        .type = 0x4D42,
        .size = 54 + dataSize,
        .reserved1 = 0,
        .reserved2 = 0,
        .offset = 54
    };

    DIBHeader dib = {
        .size = 40,
        .width = W,
        .height = H,
        .planes = 1,
        .bitCount = 24,
        .compression = 0,
        .sizeImage = dataSize,
        .xPelsPerMeter = 0,
        .yPelsPerMeter = 0,
        .clrUsed = 0,
        .clrImportant = 0
    };

    FILE *f = fopen("green-square.bmp", "wb");
    if (!f) return 1;

    fwrite(&bmp, sizeof(bmp), 1, f);
    fwrite(&dib, sizeof(dib), 1, f);

    unsigned char row[rowPadded];

    for (int y = 0; y < H; y++) {
        for (int x = 0; x < W; x++) {
            row[x*3 + 0] = 0;     // Blue
            row[x*3 + 1] = 255;     // Green
            row[x*3 + 2] = 0;   // Red
        }
        fwrite(row, 1, rowPadded, f);
    }

    fclose(f);
    return 0;
}
