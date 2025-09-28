DROP DATABASE worterbuch; 
CREATE DATABASE worterbuch; 

USE worterbuch;

SOURCE  ./worterbuch/openthesaurus_dump/openthesaurus_dump.sql;


SELECT word FROM term WHERE 
    word NOT LIKE "% %" AND
    word NOT LIKE "%(%"  AND
    word NOT LIKE "%...%" 
    
ORDER BY RAND() ASC LIMIT 10000
INTO OUTFILE '/Users/habdig7oficial/Downloads/projetos/basile_projeto/in.csv'
FIELDS TERMINATED BY ','
LINES TERMINATED BY '\n';


SELECT word FROM term WHERE 
    word LIKE ~ '[^a-zA-Zäöüß-]'
    
ORDER BY RAND() ASC LIMIT 10000
INTO OUTFILE '/Users/habdig7oficial/Downloads/projetos/basile_projeto/in.csv'
FIELDS TERMINATED BY ','
LINES TERMINATED BY '\n';