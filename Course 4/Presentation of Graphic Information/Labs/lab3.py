from PIL import Image


def main() -> int:
    image = Image.open("image2.bmp")
    image_matrix = image.load()

    rotated_matrix = []
    for i in range(image.width):
        rotated_matrix.extend([image_matrix[image.width - i - 1, image.height - j - 1] for j in range(image.height)])

    rotated_image = Image.new('RGB', (image.height, image.width))
    rotated_image.putdata(rotated_matrix)
    rotated_image.save("image_rotated.bmp", "bmp")
    return 0


if __name__ == '__main__':
    exit(main())
