all: up

makeDirs:
	mkdir -p /home/$(USER)/data/wp
	mkdir -p /home/$(USER)/data/db

up: makeDirs
	sudo docker-compose -f ./srcs/docker-compose.yml up --build -d

# quitar -d para ver los logs en tiempo real

force: makeDirs
	sudo docker-compose -f ./srcs/docker-compose.yml up --build --force-recreate -d

down:
	sudo docker-compose -f ./srcs/docker-compose.yml down

clean:
	docker stop `docker ps -qa`; \
	docker rm `docker ps -qa`; \
	docker rmi -f `docker images -qa`; \
	docker volume rm `docker volume ls -q`; \
	docker network rm `docker network ls -q`;

fclean: clean
	rm -rf /home/$(USER)/data/wp
	rm -rf /home/$(USER)/data/db

.PHONY: all up clean fclean