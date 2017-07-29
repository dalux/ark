##示例单入口框架程序结构

nginx 配置:

server {

    listen 80;
    server_name www.yourdomain.com;
    index index.php;
    root  /Users/dalu/WebSites/ark/example/demo1/public;

    location / {
        if (!-e $request_filename) {
            rewrite "^(.*)$" /index.php last;
        }
    }

    location ~ \.php {
        fastcgi_pass   127.0.0.1:9000;
        fastcgi_index  index.php;
        include        fastcgi.conf;
    }

}