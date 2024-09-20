def bayar(harga, diskonPersen=0):
    return harga - (diskonPersen*harga)/100

hargaDiskon = [500000, 300000]

harga = int(input("Masukkan harga barang : "))
diskon = 0
if harga > hargaDiskon[0]:
    print("anda dapat diskon 3%")
    diskon = 3
elif harga > hargaDiskon[1]:
    print("anda dapat diskon 1%")
    diskon = 1
else:
    print("maaf, anda tidak mendapat diskon apapun")

print("anda perlu membayar", bayar(harga, diskon), "rupiah")