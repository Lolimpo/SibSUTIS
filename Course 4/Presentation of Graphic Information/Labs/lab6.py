from PIL import Image


def main() -> int:
    image = Image.open('image.bmp')
    logo = Image.open('Google_Chrome_Logo.jpg')

    image_matrix = image.load()
    logo_matrix = logo.load()

    k = 0.5
    for i in range(logo.width):
        for j in range(logo.height):
            if logo_matrix[i, j] != (255, 255, 255):
                r = int(image_matrix[i + image.width / 2, j + image.height / 2][0] * k + logo_matrix[i, j][0] * (1 - k))
                g = int(image_matrix[i + image.width / 2, j + image.height / 2][1] * k + logo_matrix[i, j][1] * (1 - k))
                b = int(image_matrix[i + image.width / 2, j + image.height / 2][2] * k + logo_matrix[i, j][2] * (1 - k))
                image_matrix[i + image.width / 2, j + image.height / 2] = (r, g, b)

    image_plus_logo = Image.new('RGB', (image.width, image.height))
    image_plus_logo.putdata([image_matrix[i, j] for j in range(image.height) for i in range(image.width)])
    image_plus_logo.save('image+logo.bmp', 'bmp')
    image_plus_logo.show()
    return 0


if __name__ == '__main__':
    exit(main())
