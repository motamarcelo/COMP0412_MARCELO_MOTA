#!/usr/bin/env 


###CRIACAO DE VETORES DE TESTE PARA ALGORITMOS DE ORDENAÇÃO###
import argparse
import random
import os

def write_file(path, arr):
    with open(path, "w") as f:
        f.write(f"{len(arr)}\n")
        for x in arr:
            f.write(f"{x}\n")

def main():
    p = argparse.ArgumentParser(description="Gerar vetores: random, asc, desc")
    p.add_argument("--n", type=int, default=10000, help="tamanho dos vetores")
    p.add_argument("--outdir", default="data", help="diretório de saída")
    p.add_argument("--seed", type=int, default=None)
    args = p.parse_args()
    if args.seed is not None:
        random.seed(args.seed)
    os.makedirs(args.outdir, exist_ok=True)
    n = args.n
    base = [random.randint(0, 10**9) for _ in range(n)]
    write_file(os.path.join(args.outdir, "random.txt"), base)
    write_file(os.path.join(args.outdir, "asc.txt"), sorted(base))
    write_file(os.path.join(args.outdir, "desc.txt"), sorted(base, reverse=True))
    print(f"Gerado {n} elementos em {args.outdir}/{{random,asc,desc}}.txt")

if __name__ == "__main__":
    main()