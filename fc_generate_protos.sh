#!/bin/bash

# Imposta i percorsi
PROTO_DIR="ProtoFile"
OUT_DIR="gen_proto"
PROTOC="/usr/local/bin/protoc"

# Crea la directory di output se non esiste
mkdir -p "$OUT_DIR"

# Itera su ogni file .proto nella directory PROTO_DIR
for proto_file in "$PROTO_DIR"/*.proto; do
    if [ -f "$proto_file" ]; then
        echo "Generando file per: $proto_file"
        $PROTOC --proto_path="$PROTO_DIR" --cpp_out="$OUT_DIR" "$proto_file"

        if [ $? -ne 0 ]; then
            echo "Errore durante la generazione di: $proto_file"
            exit 1
        fi
    else
        echo "Nessun file .proto trovato in $PROTO_DIR"
    fi
done

echo "Generazione dei file Protobuf completata con successo."

