# Aggiungi il path ai test
INCLUDEPATH += $$PWD

# Aggiungi i file sorgente dei test
SOURCES += $$PWD/tests/test_service_message.cpp \
    $$PWD/tests/main.cpp
HEADERS += tests/test_service_message.h
# Percorso di include per Google Test
INCLUDEPATH += /usr/local/Cellar/googletest/1.15.2/include

# Percorso delle librerie
LIBS += -L/usr/local/Cellar/googletest/1.15.2/lib -lgtest -lgtest_main
