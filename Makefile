# Nom de l'exécutable final
TARGET = gestion_app

# Compilateur
CC = gcc

# Options de compilation (Wall pour afficher tous les avertissements)
CFLAGS = -Wall

# Fichiers sources
SRC = main.c boutique.c gestion_rh.c

# Fichiers objets (générés automatiquement à partir des .c)
OBJ = $(SRC:.c=.o)

# Règle par défaut : compile le projet
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

# Règle pour nettoyer les fichiers temporaires
clean:
	rm -f $(OBJ) $(TARGET)