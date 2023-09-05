
def str_to_key(str):
    out = ""
    for el in str:
        if el in "1234567890":
            out += el
        else:
            out += "%d" % ord(el)
    return int(out)
