FROM skalenetwork/sgxwallet_base:latest
WORKDIR /usr/src/sdk


RUN autoreconf -vif
RUN libtoolize --force
RUN aclocal
RUN autoheader || true
RUN automake --force-missing --add-missing
RUN autoconf
RUN ./configure
### RUN cd libBLS; cmake -H. -Bbuild; cmake --build build -- -j$(nproc);
RUN make
RUN wget --progress=dot:mega -O - https://github.com/intel/dynamic-application-loader-host-interface/archive/072d233296c15d0dcd1fb4570694d0244729f87b.tar.gz | tar -xz && \
    cd dynamic-application-loader-host-interface-072d233296c15d0dcd1fb4570694d0244729f87b && \
    cmake . -DCMAKE_BUILD_TYPE=Release -DINIT_SYSTEM=SysVinit && \
    make install && \
    cd .. && rm -rf dynamic-application-loader-host-interface-072d233296c15d0dcd1fb4570694d0244729f87b

RUN mkdir /sgx_data

COPY docker/start.sh ./
ENTRYPOINT ["/usr/src/sdk/start.sh"]
