from PIL import Image


def count_delta(left, right):
    return sum([(x - y) ** 2 for x, y in zip(left, right)], 0)


def find_palette(colors_count):
    return [i[0] for i in colors_count[:256]]


def find_closest(color_palette, color):
    res = (0, 0, 0)
    for i in color_palette:
        if count_delta(res, color) > count_delta(i, color):
            res = i
    return res


def main() -> int:
    image = Image.open('TrueColor.pcx')
    image.show()
    colors = image.getdata()

    colors_count = {}
    for color in colors:
        colors_count[color] = colors_count[color] + 1 if color in colors_count else 1
    colors_count = list(colors_count.items())
    colors_count.sort(key=lambda x: x[1], reverse=True)
    print(colors_count)

    color_palette = find_palette(colors_count)
    colors = [find_closest(color_palette, color) for color in colors]

    converted_image = Image.new('RGB', (image.width, image.height))
    converted_image.putdata(colors)
    converted_image.save('rgr-result.bmp')
    converted_image.show()
    return 0


if __name__ == '__main__':
    exit(main())
