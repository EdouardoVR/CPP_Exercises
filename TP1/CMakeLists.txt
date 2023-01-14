# Ceci est un commentaire.
# Retirez le # pour que l'instruction soit prise en compte.

# La commande ci-dessous permet de générer un exécutable à partir des fichiers spécifiés.
add_executable(
    hello-world
    helloworld.cpp
#     f2.cpp
#     f3.cpp
)

set(executables
    1-hello_world
    2-parrot
    3-array
    4-calculator
)

foreach(executable ${executables})
    add_executable(c1-${executable} chap01/${executable}.cpp)
endforeach()