#include <QtTest>

// add necessary includes here

class ClientTests : public QObject
{
    Q_OBJECT

public:
    ClientTests();
    ~ClientTests();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();
    void test_case2();
};

ClientTests::ClientTests() {}

ClientTests::~ClientTests() {}

void ClientTests::initTestCase() {}

void ClientTests::cleanupTestCase() {}

void ClientTests::test_case1()
{
    QVERIFY2(true, "Pass");
}

void ClientTests::test_case2()
{
    QVERIFY2(false, "Fail");
}

QTEST_APPLESS_MAIN(ClientTests)

#include "tst_clienttests.moc"
