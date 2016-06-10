MXE_HOME=/usr/lib/mxe/
CROSS= $(MXE_HOME)usr/bin/i686-w64-mingw32.static-
CC=g++
CFLAGS=-c -std=c++11 -Wall -O3
BIN_DIR=bin/
WINDOWS_OUTPUT=win32_build/
LINUX_OUTPUT=linux_build/
OUTPUT = $(BIN_DIR)$(LINUX_OUTPUT)
OBJ= main.o 
OBJ+= GameStateManager.o State.o MainMenuState.o PlayState.o EndGameState.o
OBJ+= Button.o StartButton.o ExitButton.o RestartButton.o MainMenuButton.o
OBJ+= Tile.o Level.o
OBJ+= Entity.o Mob.o Player.o Velociraptor.o
OBJ+= Weapon.o Projectile.o PotatoGun.o PotatoProjectile.o BananaGun.o BananaProjectile.o NyanGun.o NyanProjectile.o
OBJ+= AudioManager.o MusicManager.o SoundManager.o
EXEC_FILE=Velocicopter
LINK= -o $(EXEC_FILE) -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system

all: $(EXEC_FILE)

linux_link:
	cd $(BIN_DIR)$(LINUX_OUTPUT); $(CC) $(OBJ) $(LINK)	

pack:
	cd $(BIN_DIR); mkdir -p Linux Windows; \
	 cp -r assets/ Linux; cp -r assets/ Windows; \
	 cp $(LINUX_OUTPUT)$(EXEC_FILE) Linux/; cp $(WINDOWS_OUTPUT)$(EXEC_FILE).exe Windows/; \
	 zip -r $(EXEC_FILE).zip Linux/ Windows/;

win32 : OUTPUT = $(BIN_DIR)$(WINDOWS_OUTPUT)

win32 : CC =$(CROSS)g++

win32 : LD =$(CROSS)ld

win32 : AR =$(CROSS)ar

win32 : PKG_CONFIG =$(CROSS)pkg-config

win32 : CFLAGS+=-D_WIN32

win32 : LINK= -o $(EXEC_FILE).exe -lsfml-main -lsfml-window-s -lsfml-graphics-s -lsfml-audio-s -lsfml-system-s -lopengl32 -lgdi32 -ljpeg -lfreetype -lpng -lbz2 -lharfbuzz -lz -lglib-2.0 -lintl -lws2_32 -liconv -lsndfile -lFLAC -lvorbisfile -lvorbisenc -lvorbis -logg -ldsound -lOpenAL32 -lole32 -lwinmm 

win32: $(EXEC_FILE).exe

win32_link:
	cd $(BIN_DIR)$(WINDOWS_OUTPUT); $(CC) $(OBJ) $(LINK)

$(EXEC_FILE): $(OBJ)
	cd $(BIN_DIR)$(LINUX_OUTPUT); $(CC) $(OBJ) $(LINK)

$(EXEC_FILE).exe: $(OBJ)
	cd $(BIN_DIR)$(WINDOWS_OUTPUT); $(CC) $(OBJ) $(LINK)

main.o:
	$(CC) $(CFLAGS) main.cpp -o $(OUTPUT)$@

GameStateManager.o:
	$(CC) $(CFLAGS) states/GameStateManager.cpp -o $(OUTPUT)$@

State.o:
	$(CC) $(CFLAGS) states/State.cpp -o $(OUTPUT)$@

MainMenuState.o:
	$(CC) $(CFLAGS) states/MainMenuState.cpp -o $(OUTPUT)$@

PlayState.o:
	$(CC) $(CFLAGS) states/PlayState.cpp -o $(OUTPUT)$@

EndGameState.o:
	$(CC) $(CFLAGS) states/EndGameState.cpp -o $(OUTPUT)$@

Button.o:
	$(CC) $(CFLAGS) ui/Button.cpp -o $(OUTPUT)$@

StartButton.o:
	$(CC) $(CFLAGS) ui/StartButton.cpp -o $(OUTPUT)$@

ExitButton.o:
	$(CC) $(CFLAGS) ui/ExitButton.cpp -o $(OUTPUT)$@

RestartButton.o:
	$(CC) $(CFLAGS) ui/RestartButton.cpp -o $(OUTPUT)$@

MainMenuButton.o:
	$(CC) $(CFLAGS) ui/MainMenuButton.cpp -o $(OUTPUT)$@

Tile.o:
	$(CC) $(CFLAGS) level/Tile.cpp -o $(OUTPUT)$@

Level.o:
	$(CC) $(CFLAGS) level/Level.cpp -o $(OUTPUT)$@

Entity.o:
	$(CC) $(CFLAGS) entities/Entity.cpp -o $(OUTPUT)$@

Mob.o:
	$(CC) $(CFLAGS) entities/Mob.cpp -o $(OUTPUT)$@

Player.o:
	$(CC) $(CFLAGS) entities/Player.cpp -o $(OUTPUT)$@

Velociraptor.o:
	$(CC) $(CFLAGS) entities/Velociraptor.cpp -o $(OUTPUT)$@

Weapon.o:
	$(CC) $(CFLAGS) weapons/Weapon.cpp -o $(OUTPUT)$@

Projectile.o:
	$(CC) $(CFLAGS) weapons/Projectile.cpp -o $(OUTPUT)$@

PotatoGun.o:
	$(CC) $(CFLAGS) weapons/PotatoGun.cpp -o $(OUTPUT)$@

PotatoProjectile.o:
	$(CC) $(CFLAGS) weapons/PotatoProjectile.cpp -o $(OUTPUT)$@

BananaGun.o:
	$(CC) $(CFLAGS) weapons/BananaGun.cpp -o $(OUTPUT)$@

BananaProjectile.o:
	$(CC) $(CFLAGS) weapons/BananaProjectile.cpp -o $(OUTPUT)$@

NyanGun.o:
	$(CC) $(CFLAGS) weapons/NyanGun.cpp -o $(OUTPUT)$@

NyanProjectile.o:
	$(CC) $(CFLAGS) weapons/NyanProjectile.cpp -o $(OUTPUT)$@

AudioManager.o:
	$(CC) $(CFLAGS) audio/AudioManager.cpp -o $(OUTPUT)$@

MusicManager.o:
	$(CC) $(CFLAGS) audio/MusicManager.cpp -o $(OUTPUT)$@

SoundManager.o:
	$(CC) $(CFLAGS) audio/SoundManager.cpp -o $(OUTPUT)$@

.PHONY: clean_all
clean_all: clean clean_win32 clean_exec

.PHONY: clean
clean: 
	cd $(BIN_DIR)$(LINUX_OUTPUT);	rm -f $(OBJ) $(EXEC_FILE)

.PHONY: clean_win32
clean_win32:
	cd $(BIN_DIR)$(WINDOWS_OUTPUT); rm -f $(OBJ) $(EXEC_FILE).exe

.PHONY: clean_exec
clean_exec:
	cd $(BIN_DIR); rm -rf Linux/; rm -rf Windows/;

.PHONY: run
run:
	cp $(BIN_DIR)$(LINUX_OUTPUT)/$(EXEC_FILE) $(BIN_DIR)
	cd $(BIN_DIR); ./$(EXEC_FILE);

.PHONY: run_win32
run_win32:
	cp $(BIN_DIR)$(WINDOWS_OUTPUT)/$(EXEC_FILE).exe $(BIN_DIR)
	cd $(BIN_DIR); wine $(EXEC_FILE).exe