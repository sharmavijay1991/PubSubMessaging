#curl -O https://github.com/zeromq/libzmq/releases/download/v4.2.5/zeromq-4.2.5.tar.gz
#already uploaded in this directory: libzmq-4.2.5.tar.gz
tar -xzf libzmq-4.2.5.tar.gz
cd libzmq-4.2.5
./configure
gmake
cd -
