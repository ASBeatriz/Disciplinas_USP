import System.IO
 
data Curso = BCC | BSI | EC
    deriving (Show, Read)

-- tipo Aluno1 (Aluno2 é o construtor) (?)
-- tipo Aluno
data Aluno = Aluno([Char], Integer, Curso, [Float])
    deriving (Show, Read)

-- "struct"
data Aluno_ = Aluno_{
    nome :: [Char], 
    nusp :: Integer, 
    curso :: Curso,
    notas :: [Float]
    }
    deriving (Show, Read)



a1 = Aluno("Adenilso", 12345, BCC, [10, 6, 8, 9])

a1_ = Aluno_{
    nome = "Adenilso", 
    nusp = 12345, 
    curso = BCC, 
    notas = [10, 6, 8, 9]
}
-- muda apenas o curso
a2_ = a1_{
    curso = BSI
}

-- só defini as notas
a3_ = Aluno_{
    notas = [3, 4, 5]
}


main = do
    h <- openFile "teste.txt" ReadMode -- abre arquivo
    
    contents <- hGetContents h -- pega conteudo
    let ls = lines contents     -- pega linhas
    let l = length ls       -- pega quantidade de linhas

    putStrLn $ show ls
    putStrLn $ show l

    hClose h    -- fecha arquivo

    putStrLn $ show a1
    putStrLn $ show a1_
    putStrLn $ show a2_
    putStrLn $ show $ sum $ notas a1_
    putStrLn $ show $ sum $ notas a3_   -- isso não dá problema
    putStrLn $ show a3_ -- isso dá
