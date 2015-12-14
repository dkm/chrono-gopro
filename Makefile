# name of your application
APPLICATION = chrono-gopro

# If no BOARD is found in the environment, use this default:
BOARD ?= chronos

# This has to be the absolute path to the RIOT base directory:
RIOTBASE ?= $(CURDIR)/../RIOT
USEMODULE += xtimer
USEMODULE += cc110x
##USEMODULE += spi

# Comment this out to disable code in RIOT that does safety checking
# which is not needed in a production environment but helps in the
# development process:
CFLAGS += -DDEVELHELP -Wno-error -D__CC430__

# Change this to 0 show compiler invocation lines by default:
QUIET ?= 1

include $(RIOTBASE)/Makefile.include
