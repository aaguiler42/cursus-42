#!/bin/bash

if ! [ -f /var/www/wp/wp-config.php ]; then
if ! [ -d /var/www/wp ]; then
		mkdir -p /var/www/wp
	fi

  curl -o /wp_cli.phar https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
	chmod +x /wp_cli.phar
	mv /wp_cli.phar /usr/local/bin/wp

  wp core download --path=/var/www/wp --allow-root

  cp /var/www/wp/wp-config-sample.php /var/www/wp/wp-config.php
  sed -i "s/password_here/$MYSQL_ROOT_PASSWORD/g" /var/www/wp/wp-config.php
  sed -i "s/localhost/mariadb.inception_networkIncep/g" /var/www/wp/wp-config.php
  sed -i "s/username_here/$MYSQL_ROOT_USER/g" /var/www/wp/wp-config.php
  sed -i "s/database_name_here/$MYSQL_DATABASE/g" /var/www/wp/wp-config.php

  wp core install --allow-root --url=$WORDPRESS_URL \
    --title=$WORDPRESS_TITLE \
    --admin_user=$WORDPRESS_ADMIN \
    --admin_password=$WORDPRESS_ADMIN_PASSWORD \
    --admin_email=$WORDPRESS_ADMIN_EMAIL \
    --path=/var/www/wp

  wp user create $WORDPRESS_USER \
    $WORDPRESS_USER_EMAIL \
    --user_pass=$WORDPRESS_USER_PASSWORD \
    --role=author \
    --allow-root \
    --path=/var/www/wp
fi

chown -R wpuser /var/www/wp && chmod -R 775 /var/www/wp

php-fpm7.3 -y /etc/php/7.3/fpm/php-fpm.conf -F