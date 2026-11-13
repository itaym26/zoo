#!/usr/bin/env python3
"""Build and exercise Zoo with ASan/UBSan. Run: python3 test_zoo.py"""
from pathlib import Path
import os
import subprocess
import tempfile

ROOT = Path(__file__).resolve().parent
CASES = [
    ('empty lookup', '4\nmissing\n7\n', ['Not found']),
    ('second animal lookup', '5\n0\nAlpha\n2\n5\n0\nBeta\n3\n4\nBeta\n7\n', ['Found at index:1']),
    ('remove first and last', '5\n0\nAlpha\n2\n5\n0\nBeta\n3\n6\nAlpha\n4\nBeta\n6\nBeta\n4\nmissing\n7\n', ['Found at index:0', 'Not found']),
    ('rejected negative age', '5\n0\nInvalid\n-1\n1\n7\n', ['Could not add animal:', 'Empty zoo']),
    ('nonnumeric age', '5\n0\nInvalid\nabc\n7\n', ['Could not add animal:', 'Please enter a menu number.']),
    ('invalid menu input', 'abc\n7\n', ['Please enter a menu number.']),
    ('end of input', '', ['Zoo deleted...']),
    ('mammal truncated input', '5\n1\nMilk\n3\n', ['Could not add animal:']),
    ('insect invalid legs', '5\n2\nBug\n2\nabc\n7\n', ['Could not add animal:']),
    ('lion invalid volume', '5\n3\nLeo\n2\ny\nabc\n7\n', ['Could not add animal:']),
    ('horse invalid speed', '5\n4\nHorse\n2\ny\nabc\n7\n', ['Could not add animal:']),
    ('fly invalid lifetime', '5\n5\nFly\n1\n6\nabc\n7\n', ['Could not add animal:']),
    ('insect polymorphic noise', '5\n2\nBug\n2\n6\n2\n7\n', ['(Insect) Insect nois']),
]
with tempfile.TemporaryDirectory() as directory:
    binary = Path(directory) / 'zoo'
    subprocess.run([os.environ.get('CXX', 'c++'), '-std=c++17', '-Wall', '-Wextra', '-Werror', '-g', '-fsanitize=address,undefined', '-fno-omit-frame-pointer', *map(str, sorted((ROOT / 'zoo_project').glob('*.cpp'))), '-o', str(binary)], check=True)
    for name, input_text, expected in CASES:
        result = subprocess.run([str(binary)], input=input_text, text=True, capture_output=True, timeout=5)
        assert result.returncode == 0, (name, result.stdout, result.stderr)
        assert not result.stderr, (name, result.stderr)
        for text in expected:
            assert text in result.stdout, (name, text, result.stdout)
        print('PASS:', name)
print(f'All {len(CASES)} regression scenarios passed. This is targeted coverage, not complete API verification.')
