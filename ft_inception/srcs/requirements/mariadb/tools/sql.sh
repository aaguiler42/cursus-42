#!/bin/bash

MYSQL_ROOT_USER=$1
MYSQL_ROOT_PASSWORD=$2
MYSQL_DATABASE=$3
MYSQL_USER=$4
MYSQL_PASSWORD=$5

mv /my.cnf /etc/mysql/my.cnf

mysql_install_db
/etc/init.d/mysql start

mysql_secure_installation << EOF

y
$MYSQL_ROOT_PASSWORD
$MYSQL_ROOT_PASSWORD
y
n
y
y
EOF

echo "GRANT ALL ON *.* TO '$MYSQL_ROOT_USER'@'%' IDENTIFIED BY '$MYSQL_ROOT_PASSWORD';
FLUSH PRIVILEGES;
CREATE DATABASE IF NOT EXISTS $MYSQL_DATABASE;
CREATE USER '$MYSQL_USER'@'wordpress.inception_networkIncep' IDENTIFIED BY '$MYSQL_PASSWORD';
GRANT ALL ON *.* TO '$MYSQL_USER'@'wordpress.inception_networkIncep';
FLUSH PRIVILEGES;" | mysql -u root


sleep 3
/etc/init.d/mysql stop
sleep 3
