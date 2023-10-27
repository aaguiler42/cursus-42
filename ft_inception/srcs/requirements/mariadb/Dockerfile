FROM debian:buster

RUN apt-get update -y && apt-get install -y \
  mariadb-server \
  mariadb-client  

COPY	config/sql.conf /my.cnf
COPY	tools/sql.sh /sql.sh

RUN chmod +x /sql.sh


EXPOSE	3306

ARG MYSQL_ROOT_USER
ARG MYSQL_ROOT_PASSWORD
ARG MYSQL_DATABASE
ARG MYSQL_PASSWORD
ARG MYSQL_USER

RUN		/sql.sh $MYSQL_ROOT_USER $MYSQL_ROOT_PASSWORD $MYSQL_DATABASE $MYSQL_USER $MYSQL_PASSWORD

CMD		["mysqld"]
