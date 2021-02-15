from random import randint

from PIL import Image


def get_random_pixel() -> tuple:
    return randint(0, 255), randint(0, 255), randint(0, 255), 0


def main() -> int:
    image = Image.open("image2.bmp")
    image_matrix = image.load()

    for i in range(image.width):
        for j in range(image.height):
            if i < 15 or j < 15 or i > image.width - 15 or j > image.height - 15:
                image_matrix[i, j] = get_random_pixel()
    image.save("image_with_frame.bmp", "bmp")
    return 0


if __name__ == '__main__':
    exit(main())
