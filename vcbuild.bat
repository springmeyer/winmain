del build.sln
python gyp/gyp build.gyp --depth=. -f msvs -G msvs_version=2010
msbuild build.sln