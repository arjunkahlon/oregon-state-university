import unittest
from tasks import conv_num
from tasks import my_datetime
from tasks import conv_endian


class TestCase(unittest.TestCase):

    # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
    # conv_num tests
    def testNum1(self):
        self.assertEqual(conv_num("12345"), 12345)

    def testNum2(self):
        self.assertEqual(conv_num("123.45"), 123.45)

    def testNum3(self):
        self.assertEqual(conv_num(".45"), 0.45)

    def testNum4(self):
        self.assertEqual(conv_num("123."), 123.0)

    def testNum5(self):
        self.assertEqual(conv_num("0xAD4"), 2772)

    def testNum6(self):
        self.assertEqual(conv_num("0xAZ4"), None)

    def testNum7(self):
        self.assertEqual(conv_num("12345A"), None)

    def testNum8(self):
        self.assertEqual(conv_num("12.3.45"), None)

    # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
    # my_datetime tests
    def my_datetime_test1(self):

        self.assertEqual(my_datetime(0), '01-01-1970')

    def my_datetime_test2(self):

        self.assertEqual(my_datetime(123456789), '11-29-1973')

    def my_datetime_test3(self):

        self.assertEqual(my_datetime(9876543210), '12-22-2282')

    def my_datetime_test4(self):

        self.assertEqual(my_datetime(16344105250), '12-03-2487')

    def my_datetime_test5(self):

        self.assertEqual(my_datetime(985382050), '03-23-2001')

    def my_datetime_test6(self):

        self.assertEqual(my_datetime(92178850), '12-02-1972')

    # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
    # conv_endian tests
    def testEndian1(self):
        self.assertEqual(conv_endian(954786, 'big'), '0E 91 A2')

    def testEndian2(self):
        self.assertEqual(conv_endian(954786), '0E 91 A2')

    def testEndian3(self):
        self.assertEqual(conv_endian(-954786), '-0E 91 A2')

    def testEndian4(self):
        self.assertEqual(conv_endian(954786, 'little'), 'A2 91 0E')


if __name__ == '__main__':
    unittest.main()
