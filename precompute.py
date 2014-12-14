# -*- coding: utf-8 -*-

import pathlib

stopwords = pathlib.Path(__name__).absolute().parent / 'stopwords'

languages = []

outfile = stopwords.parent / "outfile.txt"

for item in stopwords.iterdir():
    languages.append(item)

languages.sort(key=lambda x: x.stem)

with outfile.open('w', encoding="utf-8") as of:
    of.write(";".join(l.stem for l in languages))
    of.write("\n")

    for ii, language in enumerate(languages):
        with language.open(encoding='utf-8') as f:
            print(language)
            for line in f:
                line = line.strip()
                print(line)
                if line:
                    of.write(line.strip())
                    of.write(' ')
                    of.write(str(ii))
                    of.write('\n')

