# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    run.sh                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chan <chan@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/02 12:58:29 by chan              #+#    #+#              #
#    Updated: 2021/07/02 12:58:44 by chan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

service mysql start
service php7.3-fpm start
service nginx start

if [ ${AUTOINDEX} -eq -1 ]; then
        sed -i 's/autoindex on;/autoindex off;/g' /etc/nginx/sites-available/default
fi
bash
