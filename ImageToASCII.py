import PIL.Image

attela_nosaukums = input("Lūdzu, izvēlies, kuru attēlu Tu vēlies pārveidot:")
attels = PIL.Image.open(attela_nosaukums)
print(attels)

sakuma_platums = attels.width
sakuma_garums = attels.height
proporcija = sakuma_platums / sakuma_garums
jaunais_platums = 40
jaunais_garums = int(proporcija * jaunais_platums)
jaunais_attels = attels.resize((jaunais_platums, jaunais_garums))
print(jaunais_attels)

mb_attels = jaunais_attels.convert("L")

ascii = ["#", "@", "%", "$", "&", "8", "9", "+", "*", ",", "."]

pikseli = mb_attels.getdata()
rinda = ""

for pikselis in pikseli:
   rinda = rinda + ascii[pikselis//25]

print(rinda)

zimejums = ""

for simbols in range(len(rinda)):
    if simbols % jaunais_platums == 0:
        zimejums = zimejums + "\n" + rinda[simbols]
    else:
        zimejums = zimejums + rinda[simbols]

print(zimejums)

with open("ascii_image.txt", "w") as f:
    f.write(zimejums)
