import io

import pygame
from PIL import Image

image = Image.open("200001.PCX")
image_bytes = io.BytesIO()
image.save(image_bytes, "PCX")
image_bytes = bytes(image_bytes.getvalue())

# Constants
FPS = 30
W = int.from_bytes(image_bytes[8:10], "little") + 1
H = int.from_bytes(image_bytes[10:12], "little") + 1

pygame.init()
pygame.display.set_caption("Lab8")
sc = pygame.display.set_mode((W, H))
clock = pygame.time.Clock()


def main():
    color_palette = [
        (image_bytes[i], image_bytes[i + 1], image_bytes[i + 2])
        for i in range(len(image_bytes) - 768, len(image_bytes), 3)
    ]

    i = 128
    decoded_image = []
    while i < len(image_bytes) - 768:
        if (image_bytes[i] & 0xC0) == 0xC0:
            row = image_bytes[i] & 0x3F
            for _ in range(row):
                decoded_image.append(color_palette[image_bytes[i + 1]])
            i += 2
        else:
            decoded_image.append(color_palette[image_bytes[i + 1]])
            i += 1

    while True:
        clock.tick(FPS)

        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                exit(0)

        for i in range(H):
            for j in range(W):
                # print(decoded_image[i * W + j])
                pygame.draw.line(sc, decoded_image[i * W + j], (j, i), (j, i))
        pygame.display.update()


if __name__ == "__main__":
    exit(main())
