#!/usr/bin/env python3
"""Compile actual independent examples; run deterministic CPU-only behavior contracts."""
import argparse, datetime, json, pathlib, shutil, subprocess, tempfile
ROOT=pathlib.Path(__file__).resolve().parents[4]
p=argparse.ArgumentParser();p.add_argument('command',choices=['doctor','drive']);p.add_argument('--out',default='.verification-evidence');a=p.parse_args()
out=pathlib.Path(a.out).resolve();out.mkdir(parents=True,exist_ok=True)
r={'command':a.command,'at':datetime.datetime.now(datetime.timezone.utc).isoformat(),'root':str(ROOT),'steps':[],'ok':False}
def run(argv,cwd):
 q=subprocess.run(argv,cwd=cwd,capture_output=True,text=True,timeout=15)
 r['steps'].append({'argv':argv,'exit':q.returncode,'stdout':q.stdout,'stderr':q.stderr})
 if q.returncode:raise RuntimeError('Command failed: '+argv[0])
 return q.stdout
try:
 assert shutil.which('g++'),'g++ required'
 assert (ROOT/'Algorithms/quicksort.cpp').is_file(),'Wrong repository root'
 run(['g++','--version'],ROOT)
 if a.command=='drive':
  with tempfile.TemporaryDirectory(prefix='cpp-verification-') as tmp:
   t=pathlib.Path(tmp)
   checks=[('Algorithms/bubble_sort.cpp','7 9 13 34 56'),('Algorithms/quicksort.cpp','1 5 7 8 9 10'),('simple_gcd.cpp','4'),('c++17/variant.cpp','50\n50.5'),('c++17/optional.cpp','Class is not yet Constructed\nObject ConstructedSecond try: 42'),('c++17/parse_url_std_optional.cpp','')]
   for i,(source,expected) in enumerate(checks):
    exe=str(t/str(i));run(['g++','-std=c++17','-Wall','-Wextra','-Werror=return-type',str(ROOT/source),'-o',exe],t)
    got=run([exe],t).strip();assert got==expected,(source,expected,got)
   # Include actual source under a renamed demonstration main, preserving implementation.
   h=t/'binary.cpp';h.write_text('#define main example_main\n#include "'+str(ROOT/'Algorithms/binary_search_recursion.cpp')+'"\n#undef main\n#include <cassert>\nint main(){std::vector<int> v{2,4,6,8,10}; assert(doBinarySearch(v,0,4,2)==0); assert(doBinarySearch(v,0,4,10)==4); assert(doBinarySearch(v,0,4,6)==2); assert(doBinarySearch(v,0,4,7)==-1); assert(doBinarySearch(v,0,-1,1)==-1);}\n')
   exe=str(t/'binary');run(['g++','-std=c++17','-Wall','-Wextra','-Werror=return-type',str(h),'-o',exe],t);run([exe],t)
 r['ok']=True
except Exception as e:r['failure']=str(e)
(out/(a.command+'.json')).write_text(json.dumps(r,indent=2)+'\n');print(json.dumps(r,indent=2));raise SystemExit(0 if r['ok'] else 1)
