import binascii


def CRC32_get(filename):
    file = open(filename, 'rb').read()
    file = (binascii.crc32(file) & 0xFFFFFFFF)
    return "%08X" % file


if __name__ == '__main__':
    print(f"Result:{CRC32_get('text.txt')}")
