
{
  'targets': [
    {
      'target_name': 'test-c',
      'product_name': 'test-c',
      'type': 'executable',
      'product_prefix': '',
      'product_extension':'exe',
      'sources': [
        'test.cpp',
      ],
      'defines': [
        'PLATFORM="<(OS)"',
        '_LARGEFILE_SOURCE',
        '_FILE_OFFSET_BITS=64',
      ],
      'conditions': [
        [ 'OS=="mac"', {
          'libraries': [
            '-undefined dynamic_lookup'
          ],
          'include_dirs': [
          ],
        }],
        [ 'OS=="win"', {
          'defines': [
            'PLATFORM="win32"',
            '_LARGEFILE_SOURCE',
            '_FILE_OFFSET_BITS=64',
            '_WINDOWS',
          ],
          'libraries': [ 
          ],
          'include_dirs': [
          ],
          'msvs_settings': {
            'VCLinkerTool': {
			  'SubSystem': 2,
              'AdditionalLibraryDirectories': [
              ],
            },
          },
        },
      ], # windows
      ] # condition
    }, # targets
  ],
}