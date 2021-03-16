import io

from PIL import Image


def main() -> int:
    """Putting text to BMP"""
    image = Image.open("true_color.bmp")
    image_bytes = io.BytesIO()
    image.save(image_bytes, "BMP")
    image_bytes = bytearray(image_bytes.getvalue())

    with open("text.txt", "r") as f:
        text = f.read()
        # print('Original text:', text)
        text_to_bits = "".join([bin(ord(i))[2:].zfill(8) for i in text])
        print("Original text size:", len(text_to_bits))
        text_to_bits_binary = bin(len(text_to_bits))[2:].zfill(64)

    for i in range(64):
        image_bytes[i + 64] &= ~1
        image_bytes[i + 64] |= int(text_to_bits_binary[i])

    free_bytes = len(image_bytes) - 128

    for i in range(len(text_to_bits)):
        byte_index = 128 + i * free_bytes // len(text_to_bits)
        image_bytes[byte_index] &= ~1
        image_bytes[byte_index] |= int(text_to_bits[i])

    new_image = Image.open(io.BytesIO(image_bytes))
    new_image.save("lab7.bmp", "BMP")

    """Reading text from BMP"""
    image = Image.open("lab7.bmp")
    image_bytes = io.BytesIO()
    image.save(image_bytes, "BMP")
    image_bytes = bytearray(image_bytes.getvalue())

    text_size_bits = "".join(str(image_bytes[i + 64] & 1) for i in range(64))
    text_size = int(text_size_bits, 2)
    print("Decoded text size:", text_size)

    free_bytes = len(image_bytes) - 128

    text_to_bits = ""
    for i in range(text_size):
        byte_index = 128 + i * free_bytes // text_size
        text_to_bits += str(image_bytes[byte_index] & 1)

    text = "".join(
        [chr(int(text_to_bits[i * 8: (i + 1) * 8], 2)) for i in range(text_size // 8)]
    )
    # print('Decoded text:', text)

    return 0


if __name__ == "__main__":
    exit(main())
