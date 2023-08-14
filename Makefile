##
## EPITECH PROJECT, 2023
## rayanTracer
## File description:
## Makefile
##

SRC	=	main.cpp	\
	src/Ray.cpp	\
	src/Camera.cpp	\
	src/Scene.cpp	\
	src/Factory.cpp	\
	src/utils/Vector3D.cpp	\
	src/utils/Point3D.cpp	\
	src/utils/Color.cpp	\
	src/utils/Light.cpp	\
	src/utils/DirectionnalLight.cpp	\
	src/objects/Hittable.cpp	\
	src/objects/Sphere.cpp	\
	src/objects/Cone.cpp	\
	src/objects/Plane.cpp	\
	src/materials/Mate.cpp	\
	src/materials/Standard.cpp	\
	src/materials/AMaterial.cpp	\
	src/Parser.cpp	\

INC_PATH	=	includes	\
			includes/objects	\
			includes/utils	\
			includes/materials	\

OBJ	=	$(SRC:.cpp=.o)

NAME	=	raytracer

CFLAGS	=	-Wall -Wextra

CPPFLAGS	=	$(INC_PATH:%=-I %)

%.o: %.cpp
	g++ -o $@ -c $< $(CPPFLAGS) $(CFLAGS)

all:	$(NAME)

$(NAME):	$(OBJ)
	g++ -o $(NAME) $(OBJ) $(CFLAGS) -lconfig++

debug: CFLAGS += -g
debug: re

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re debug
