
void* insertWord(void* arg1, void* arg2, int64_t arg3)
{
    void* var_10 = arg1;
    int32_t var_14 = 0;
    while (true)
    {
        if (*(arg2 + var_14) == 0)
        {
            *(var_10 + 0x1a0) = arg3;
            return var_10;
        }
        int32_t var_18_1;
        if ((*(arg2 + var_14) > 0x60 && *(arg2 + var_14) <= 0x7a))
        {
            var_18_1 = (*(arg2 + var_14) - 0x61);
        }
        if ((((*(arg2 + var_14) <= 0x60 || (*(arg2 + var_14) > 0x60 && *(arg2 + var_14) > 0x7a)) && *(arg2 + var_14) > 0x40) && *(arg2 + var_14) <= 0x5a))
        {
            var_18_1 = (*(arg2 + var_14) - 0x27);
        }
        if (((*(arg2 + var_14) > 0x60 && *(arg2 + var_14) <= 0x7a) || (((*(arg2 + var_14) <= 0x60 || (*(arg2 + var_14) > 0x60 && *(arg2 + var_14) > 0x7a)) && *(arg2 + var_14) > 0x40) && *(arg2 + var_14) <= 0x5a)))
        {
            if (*(var_10 + (var_18_1 << 3)) != 0)
            {
                break;
            }
            *(var_10 + (var_18_1 << 3)) = createNode();
        label_4016be:
            var_10 = *(var_10 + (var_18_1 << 3));
        }
        var_14 = (var_14 + 1);
    }
    goto label_4016be;
}

int64_t searchWord(int64_t arg1, void* arg2)
{
    int64_t var_10 = arg1;
    int32_t var_14 = 0;
    int64_t rax_31;
    while (true)
    {
        if (*(arg2 + var_14) == 0)
        {
            rax_31 = var_10;
            break;
        }
        int32_t var_18_1;
        if ((*(arg2 + var_14) > 0x60 && *(arg2 + var_14) <= 0x7a))
        {
            var_18_1 = (*(arg2 + var_14) - 0x61);
        }
        if ((*(arg2 + var_14) <= 0x60 || (*(arg2 + var_14) > 0x60 && *(arg2 + var_14) > 0x7a)))
        {
            if ((*(arg2 + var_14) <= 0x40 || (*(arg2 + var_14) > 0x40 && *(arg2 + var_14) > 0x5a)))
            {
                rax_31 = 0;
                break;
            }
            if ((*(arg2 + var_14) > 0x40 && *(arg2 + var_14) <= 0x5a))
            {
                var_18_1 = (*(arg2 + var_14) - 0x27);
            }
        }
        if (((*(arg2 + var_14) > 0x60 && *(arg2 + var_14) <= 0x7a) || (((*(arg2 + var_14) <= 0x60 || (*(arg2 + var_14) > 0x60 && *(arg2 + var_14) > 0x7a)) && *(arg2 + var_14) > 0x40) && *(arg2 + var_14) <= 0x5a)))
        {
            if (*(var_10 + (var_18_1 << 3)) == 0)
            {
                rax_31 = 0;
                break;
            }
            var_10 = *(var_10 + (var_18_1 << 3));
            var_14 = (var_14 + 1);
        }
    }
    return rax_31;
}

int64_t checkStringLength(char* arg1)
{
    int64_t rax_1;
    if (strlen(arg1) <= 1)
    {
        rax_1 = 0;
    }
    else
    {
        rax_1 = 1;
    }
    return rax_1;
}

uint64_t countWords(char* arg1)
{
    arg_8 = arg1;
    int32_t var_c = 0;
    int32_t var_10 = 0;
    while (*arg_8 != 0)
    {
        if ((((*arg_8 != 0x20 && *arg_8 != 9) && *arg_8 != 0xa) && *arg_8 != 0xd))
        {
            var_10 = 1;
        }
        if (((((*arg_8 == 0x20 || *arg_8 == 9) || *arg_8 == 0xa) || *arg_8 == 0xd) && var_10 != 0))
        {
            var_c = (var_c + 1);
            var_10 = 0;
        }
        arg_8 = &arg_8[1];
    }
    if (var_10 != 0)
    {
        var_c = (var_c + 1);
    }
    return var_c;
}

int64_t releaseSlangWord(void* arg1)
{
    void var_e8;
    char i;
    do
    {
        printf("Input a new slang word [Must be …");
        scanf(" %[^\n]", &var_e8);
        int32_t rax_1 = checkStringLength(&var_e8);
        int32_t rax_2;
        if (rax_1 == 1)
        {
            rax_2 = containsSpace(&var_e8);
            if (rax_2 == 0)
            {
                i = 0;
            }
        }
        if ((rax_1 != 1 || (rax_1 == 1 && rax_2 != 0)))
        {
            i = 1;
        }
    } while (i != 0);
    void _Source;
    int32_t rax_3;
    do
    {
        printf("Input a new slang word descripti…");
        scanf(" %[^\n]", &_Source);
        rax_3 = countWords(&_Source) <= 1;
    } while (rax_3 != 0);
    void* rax_4 = searchWord(arg1, &var_e8);
    if (rax_4 == 0)
    {
        puts(&data_405099);
        puts("Successfully released new slang …");
        insertWord(arg1, &var_e8, _strdup(&_Source));
    }
    else
    {
        puts(&data_405099);
        puts("Successfully updated a slang wor…");
        *(rax_4 + 0x1a0) = _strdup(&_Source);
    }
    puts("Press enter to continue...");
    return getchar();
}

void clearScreen()
{
    for (int32_t i = 0; i <= 0x31; i = (i + 1))
    {
        putchar(0xa);
    }
}

int64_t displayMainMenu()
{
    puts("BOOGLE");
    puts("1. Release a new slang word");
    puts("2. Search a slang word");
    puts("3. View all slang words starting…");
    puts("4. View all slang words");
    return puts("5. Exit");
}

int64_t searchSlangWord(int64_t arg1)
{
    void var_78;
    char i;
    do
    {
        printf("Input a slang word to be searche…");
        scanf(" %[^\n]", &var_78);
        int32_t rax_1 = checkStringLength(&var_78);
        int32_t rax_2;
        if (rax_1 == 1)
        {
            rax_2 = containsSpace(&var_78);
            if (rax_2 == 0)
            {
                i = 0;
            }
        }
        if ((rax_1 != 1 || (rax_1 == 1 && rax_2 != 0)))
        {
            i = 1;
        }
    } while (i != 0);
    void* rax_3 = searchWord(arg1, &var_78);
    if ((rax_3 == 0 || (rax_3 != 0 && *(rax_3 + 0x1a0) == 0)))
    {
        puts(&data_405099);
        printf("There is no word "%s" in the dic…", &var_78);
    }
    if ((rax_3 != 0 && *(rax_3 + 0x1a0) != 0))
    {
        puts(&data_405099);
        printf("Slang word: %s\n", &var_78);
        printf("Description: %s\n\n", *(rax_3 + 0x1a0));
    }
    puts("Press enter to continue...");
    return getchar();
}

void displaySlangWordsUtil(void* arg1, void* arg2, int32_t arg3, int32_t* arg4)
{
    if (arg1 != 0)
    {
        if (*(arg1 + 0x1a0) != 0)
        {
            *(arg2 + arg3) = 0;
            int32_t rax_6 = *arg4;
            *arg4 = (rax_6 + 1);
            printf("%d. %s\n", rax_6, arg2);
        }
        for (int32_t i = 0; i <= 0x33; i = (i + 1))
        {
            if (*(arg1 + (i << 3)) != 0)
            {
                if (i > 0x19)
                {
                    *(arg2 + arg3) = (i + 0x27);
                }
                else
                {
                    *(arg2 + arg3) = (i + 0x61);
                }
                displaySlangWordsUtil(*(arg1 + (i << 3)), arg2, (arg3 + 1), arg4);
            }
        }
    }
}

int64_t displaySlangWords(void* arg1)
{
    puts("\nList of all slang words in the…");
    int32_t var_c = 1;
    char var_78;
    displaySlangWordsUtil(arg1, &var_78, 0, &var_c);
    if (var_78 == 0)
    {
        puts("There is no slang word yet in th…");
    }
    puts("Press enter to continue...");
    return getchar();
}

int64_t displayLex(int64_t arg1)
{
    void _Str;
    char i;
    do
    {
        printf("Input a prefix to be searched: ");
        scanf(" %[^\n]", &_Str);
        int32_t rax_1 = checkStringLength(&_Str);
        int32_t rax_2;
        if (rax_1 == 1)
        {
            rax_2 = containsSpace(&_Str);
            if (rax_2 == 0)
            {
                i = 0;
            }
        }
        if ((rax_1 != 1 || (rax_1 == 1 && rax_2 != 0)))
        {
            i = 1;
        }
    } while (i != 0);
    void* rax_3 = searchWord(arg1, &_Str);
    if (rax_3 != 0)
    {
        printf("Words starts with "%s":\n", &_Str);
        int32_t var_14 = 1;
        displaySlangWordsUtil(rax_3, &_Str, strlen(&_Str), &var_14);
    }
    else
    {
        printf("There is no prefix "%s" in the d…", &_Str);
    }
    puts("Press enter to continue...");
    return getchar();
}

int64_t main()
{
    __main();
    void* rax = createNode();
    int32_t i;
    do
    {
        clearScreen();
        displayMainMenu();
        scanf(&data_405325, &i);
        getchar();
        switch (i)
        {
            case 1:
            {
                releaseSlangWord(rax);
                getchar();
                break;
            }
            case 2:
            {
                searchSlangWord(rax);
                getchar();
                break;
            }
            case 3:
            {
                displayLex(rax);
                getchar();
                break;
            }
            case 4:
            {
                displaySlangWords(rax);
                break;
            }
            case 5:
            {
                clearScreen();
                printf("Thank you... Have a nice day :)");
                getchar();
                break;
                break;
            }
        }
    } while (i != 5);
    return 0;
}

void* _decode_pointer(void* codedptr) __pure
{
    return codedptr;
}

void* _encode_pointer(void* ptr) __pure
{
    return ptr;
}

int _setargv() __pure
{
    return 0;
}

int (*)() __mingw_raise_matherr(int typ, char const* name, double a1, double a2, double rslt)
{
    int (* stUserMathErr_1)() = stUserMathErr;
    if (stUserMathErr_1 != 0)
    {
        int typ_1 = typ;
        char const* name_1 = name;
        double a1_1 = a1;
        double a2_1 = a2;
        double rslt_1 = rslt;
        stUserMathErr_1 = stUserMathErr_1();
    }
    return stUserMathErr_1;
}

int64_t __mingw_setusermatherr(int (* f)())
{
    stUserMathErr = f;
    /* tailcall */
    return __setusermatherr(f);
}

int _matherr(struct _exception* pexcept)
{
    char const* const rbx;
    switch (pexcept->type)
    {
        case 1:
        {
            rbx = "Argument domain error (DOMAIN)";
            break;
        }
        case 2:
        {
            rbx = "Argument singularity (SIGN)";
            break;
        }
        case 3:
        {
            rbx = "Overflow range error (OVERFLOW)";
            break;
        }
        case 4:
        {
            rbx = "The result is too small to be re…";
            break;
        }
        case 5:
        {
            rbx = "Total loss of significance (TLOS…";
            break;
        }
        case 6:
        {
            rbx = "Partial loss of significance (PL…";
            break;
        }
        default:
            rbx = "Unknown error";
    }
    fprintf(&__iob_func()[0xc], "_matherr(): %s in %s(%g, %g)  (r…", rbx, pexcept->name, pexcept->arg1, pexcept->arg2, pexcept->retval);
    return 0;
}

void __report_error(char const* msg) __noreturn
{
    int64_t _ArgList_1;
    _ArgList = _ArgList_1;
    int64_t r8;
    arg_18 = r8;
    int64_t r9;
    arg_20 = r9;
    fwrite("Mingw-w64 runtime failure:\n", 1, 0x1b, &__iob_func()[0xc]);
    vfprintf(&__iob_func()[0xc], msg, &_ArgList);
    abort();
    /* no return */
}

int64_t __write_memory(void* addr, void const* src, long long unsigned int len)
{
    int64_t maxSections_1 = maxSections;
    unsigned char** rax_2;
    unsigned char* sec_start;
    if (maxSections_1 <= 0)
    {
        maxSections_1 = 0;
    }
    else
    {
        int32_t i = 0;
        rax_2 = &the_secs->sec_start;
        do
        {
            sec_start = (rax_2 - 8)->sec_start;
            if ((addr >= sec_start && addr < &sec_start[(rax_2 - 8)->hash->Misc]))
            {
                break;
            }
            i = (i + 1);
            rax_2 = &rax_2[3];
        } while (i != maxSections_1);
    }
    if ((maxSections_1 <= 0 || (maxSections_1 > 0 && !((addr >= sec_start && addr < (sec_start + *(*((rax_2 - 8) + 0x10) + 8)))))))
    {
        void* rax_3 = __mingw_GetSectionForAddress(addr);
        if (rax_3 == 0)
        {
            __report_error("Address %p has no image-section");
            /* no return */
        }
        int64_t rbp_1 = (maxSections_1 * 0x18);
        void* r13_2 = (rbp_1 + the_secs);
        *(r13_2 + 0x10) = rax_3;
        *r13_2 = 0;
        *(r13_2 + 8) = (_GetPEImageBase() + *(rax_3 + 0xc));
        int64_t var_68;
        if (VirtualQuery(*(&the_secs->sec_start + rbp_1), &var_68, 0x30) == 0)
        {
            *(rax_3 + 8);
            *(&the_secs->sec_start + rbp_1);
            __report_error("  VirtualQuery failed for %d byt…");
            /* no return */
        }
        uint64_t dwSize;
        int32_t var_44;
        if (((((var_44 - 4) & 0xfffffffb) != 0 && ((var_44 - 0x40) & 0xffffffbf) != 0) && VirtualProtect(var_68, dwSize, PAGE_EXECUTE_READWRITE, (rbp_1 + the_secs)) == 0))
        {
            GetLastError();
            __report_error("  VirtualProtect failed with cod…");
            /* no return */
        }
        maxSections = (maxSections + 1);
    }
    /* tailcall */
    return memcpy(addr, src, len);
}

void _pei386_runtime_relocator()
{
    if (was_init == 0)
    {
        was_init = 1;
        void* rax_5 = (((__mingw_GetSectionCount() * 0x18) + 0x1e) & 0xfffffffffffffff0);
        _.text(rax_5);
        maxSections = 0;
        void var_98;
        the_secs = ((&var_98 - rax_5) + 0x20);
    }
}

int __mingw_SEH_error_handler(struct _EXCEPTION_RECORD* ExceptionRecord, void* EstablisherFrame, struct _CONTEXT* ContextRecord, void* DispatcherContext)
{
    uint32_t ExceptionCode = ExceptionRecord->ExceptionCode;
    int64_t rax_1;
    _crt_signal_t rdx;
    if (ExceptionCode == 0xc0000094)
    {
        _crt_signal_t rax_7 = signal(8, nullptr);
        rdx = rax_7;
        if (rax_7 == 1)
        {
            signal(8, 1);
            rax_1 = 0;
        label_402577:
            return rax_1;
        }
    }
    if ((ExceptionCode > 0xc0000091 && ExceptionCode != 0xc0000094))
    {
        if (ExceptionCode > 0xc0000094)
        {
            if (ExceptionCode == 0xc0000095)
            {
                goto label_402646;
            }
            if (ExceptionCode != 0xc0000096)
            {
            label_402627:
                return 1;
            }
        label_4025e5:
            _crt_signal_t rax_4 = signal(4, nullptr);
            if (rax_4 == 1)
            {
                signal(4, 1);
                rax_1 = 0;
                goto label_402577;
            }
            if (rax_4 != 0)
            {
                rax_4(4);
                rax_1 = 0;
                goto label_402577;
            }
        label_402689:
            return 4;
        }
        if (ExceptionCode == 0xc0000092)
        {
            goto label_402646;
        }
        if (ExceptionCode != 0xc0000093)
        {
            goto label_402627;
        }
    }
    if ((ExceptionCode <= 0xc0000091 && ExceptionCode < 0xc000008d))
    {
        if (ExceptionCode == 0xc0000008)
        {
            goto label_402646;
        }
        if (ExceptionCode > 0xc0000008)
        {
            if (ExceptionCode != 0xc000001d)
            {
                if (ExceptionCode == 0xc000008c)
                {
                    goto label_402646;
                }
                goto label_402627;
            }
            goto label_4025e5;
        }
        if (ExceptionCode == 0x80000002)
        {
            goto label_402646;
        }
        if (ExceptionCode != 0xc0000005)
        {
            goto label_402627;
        }
        _crt_signal_t rax = signal(0xb, nullptr);
        if (rax == 1)
        {
            signal(0xb, 1);
            rax_1 = 0;
            goto label_402577;
        }
        if (rax != 0)
        {
            rax(0xb);
            rax_1 = 0;
            goto label_402577;
        }
        goto label_402689;
    }
    if (((ExceptionCode > 0xc0000091 && ExceptionCode != 0xc0000094) || ExceptionCode <= 0xc0000091))
    {
        _crt_signal_t rax_2 = signal(8, nullptr);
        rdx = rax_2;
        if (rax_2 == 1)
        {
            signal(8, 1);
        label_402646:
            return 0;
        }
    }
    rax_1 = 1;
    if (rdx != 0)
    {
        rdx(8);
        return 0;
    }
    goto label_402577;
}

int __mingw_init_ehandler()
{
    uint64_t BaseAddress = _GetPEImageBase();
    int was_here_1 = was_here;
    if ((was_here_1 == 0 && BaseAddress != 0))
    {
        was_here = 1;
        char* rax = _FindPESectionByName(".pdata");
        if (rax == 0)
        {
            struct _RUNTIME_FUNCTION* rbx_1 = &emu_pdata;
            long long unsigned int eNo = 0;
            int64_t rcx_1;
            int64_t rdi_1;
            rdi_1 = __memfill_u64(&emu_pdata, rax, 0x180);
            rcx_1 = 0x20;
            int64_t rcx_2;
            int64_t rdi_2;
            rdi_2 = __memfill_u64(&emu_xdata, rax, (rcx_1 << 3));
            struct _UNWIND_INFO* rdi_3 = &emu_xdata;
            while (true)
            {
                void* rax_3 = _FindPESectionExec(eNo);
                uint32_t EntryCount;
                if (rax_3 != 0)
                {
                    rdi_3->VersionAndFlags = 9;
                    rdi_3->AddressOfExceptionHandler = (0x402510 - BaseAddress);
                    eNo = (eNo + 1);
                    int32_t rdx_1 = *(rax_3 + 0xc);
                    rbx_1 = &rbx_1[1];
                    *(rbx_1 - 0xc) = rdx_1;
                    int32_t rax_2 = (rdi_3 - BaseAddress);
                    rdi_3 = &rdi_3[1];
                    rbx_1[0].BeginAddress = rax_2;
                    *(rbx_1 - 8) = (rdx_1 + *(rax_3 + 8));
                    if (eNo != 0x20)
                    {
                        continue;
                    }
                    else
                    {
                        EntryCount = 0x20;
                    }
                }
                else
                {
                    if (eNo == 0)
                    {
                        break;
                    }
                    EntryCount = eNo;
                }
                RtlAddFunctionTable(&emu_pdata, EntryCount, BaseAddress);
                break;
            }
        }
        was_here_1 = 1;
    }
    return was_here_1;
}

long int (*)() _gnu_exception_handler(struct _EXCEPTION_POINTERS* exception_data)
{
    EXCEPTION_RECORD* ExceptionRecord = exception_data->ExceptionRecord;
    uint32_t ExceptionCode = ExceptionRecord->ExceptionCode;
    if (((ExceptionCode & 0x20ffffff) == 0x20474343 && (ExceptionRecord->ExceptionFlags & 1) == 0))
    {
        goto label_402823;
    }
    long int (* __mingw_oldexcpt_handler_1)();
    _crt_signal_t rax_2;
    if (ExceptionCode == 0xc0000094)
    {
        rax_2 = signal(8, nullptr);
        if (rax_2 == 1)
        {
            signal(8, 1);
        label_402823:
            __mingw_oldexcpt_handler_1 = 0xffffffff;
        }
    }
    if ((ExceptionCode > 0xc0000091 && ExceptionCode != 0xc0000094))
    {
        if (ExceptionCode > 0xc0000094)
        {
            if (ExceptionCode == 0xc0000095)
            {
                goto label_402823;
            }
            if (ExceptionCode != 0xc0000096)
            {
                goto label_402842;
            }
        }
        else
        {
            if (ExceptionCode == 0xc0000092)
            {
                goto label_402823;
            }
            if (ExceptionCode != 0xc0000093)
            {
                goto label_402842;
            }
        }
    }
    if (((ExceptionCode <= 0xc0000091 && ExceptionCode >= 0xc000008d) || ((ExceptionCode > 0xc0000091 && ExceptionCode != 0xc0000094) && ExceptionCode <= 0xc0000094)))
    {
        rax_2 = signal(8, nullptr);
        if (rax_2 == 1)
        {
            signal(8, 1);
            goto label_402823;
        }
    }
    if ((((ExceptionCode == 0xc0000094 && rax_2 != 1) || (ExceptionCode <= 0xc0000091 && ExceptionCode >= 0xc000008d)) || ((ExceptionCode > 0xc0000091 && ExceptionCode != 0xc0000094) && ExceptionCode <= 0xc0000094)))
    {
        if (rax_2 != 0)
        {
            rax_2(8);
            __mingw_oldexcpt_handler_1 = 0xffffffff;
        }
        else
        {
        label_402842:
            __mingw_oldexcpt_handler_1 = __mingw_oldexcpt_handler;
            if (__mingw_oldexcpt_handler_1 != 0)
            {
                /* tailcall */
                return __mingw_oldexcpt_handler_1();
            }
        }
    }
    if ((ExceptionCode <= 0xc0000091 && ExceptionCode < 0xc000008d))
    {
        if (ExceptionCode == 0xc0000008)
        {
            goto label_402823;
        }
        if (ExceptionCode <= 0xc0000008)
        {
            if (ExceptionCode == 0x80000002)
            {
                goto label_402823;
            }
            if (ExceptionCode != 0xc0000005)
            {
                goto label_402842;
            }
            _crt_signal_t rax = signal(0xb, nullptr);
            if (rax == 1)
            {
                signal(0xb, 1);
                goto label_402823;
            }
            if (rax == 0)
            {
                goto label_402842;
            }
            rax(0xb);
            goto label_402823;
        }
        if (ExceptionCode != 0xc000001d)
        {
            if (ExceptionCode == 0xc000008c)
            {
                goto label_402823;
            }
            goto label_402842;
        }
    }
    if ((((ExceptionCode > 0xc0000091 && ExceptionCode != 0xc0000094) && ExceptionCode > 0xc0000094) || (ExceptionCode <= 0xc0000091 && ExceptionCode < 0xc000008d)))
    {
        _crt_signal_t rax_3 = signal(4, nullptr);
        if (rax_3 == 1)
        {
            signal(4, 1);
            goto label_402823;
        }
        if (rax_3 == 0)
        {
            goto label_402842;
        }
        rax_3(4);
        __mingw_oldexcpt_handler_1 = 0xffffffff;
    }
    return __mingw_oldexcpt_handler_1;
}

void _fpreset() __pure
{
    return;
}

void __do_global_dtors()
{
    void (* i)() = **&p;
    if (i != 0)
    {
        do
        {
            i();
            void (** p_1)() = p;
            i = p_1[1];
            p = &p_1[1];
        } while (i != 0);
    }
}

int64_t __do_global_ctors()
{
    int32_t i_1 = 0;
    while (true)
    {
        uint64_t rdx_2 = (i_1 + 1);
        if (__CTOR_LIST__[rdx_2] == 0)
        {
            break;
        }
        i_1 = rdx_2;
    }
    if (i_1 != 0)
    {
        int32_t i;
        do
        {
            __CTOR_LIST__[i_1]();
            i = i_1;
            i_1 = (i_1 - 1);
        } while (i != 1);
    }
    /* tailcall */
    return atexit(__do_global_dtors);
}

int __main()
{
    int initialized_1 = initialized;
    if (initialized_1 == 0)
    {
        initialized = 1;
        /* tailcall */
        return __do_global_ctors();
    }
    return initialized_1;
}

void __security_init_cookie()
{
    long long unsigned int __security_cookie_1 = __security_cookie;
    int64_t lpSystemTimeAsFileTime = 0;
    if (__security_cookie_1 != 0x2b992ddfa232)
    {
        __security_cookie_complement = !(__security_cookie_1);
        return;
    }
    GetSystemTimeAsFileTime(&lpSystemTimeAsFileTime);
    int64_t lpSystemTimeAsFileTime_1 = lpSystemTimeAsFileTime;
    uint64_t rbp = GetCurrentProcessId();
    uint32_t rax_1 = GetCurrentThreadId();
    uint32_t rax_2 = GetTickCount();
    int64_t lpPerformanceCount;
    QueryPerformanceCounter(&lpPerformanceCount);
    long long unsigned int rsi_2 = ((((rbp ^ (lpSystemTimeAsFileTime_1 ^ lpPerformanceCount)) ^ rax_1) ^ rax_2) & 0xffffffffffff);
    int64_t rax_4;
    if (rsi_2 == __security_cookie_1)
    {
        rax_4 = -0x2b992ddfa234;
        rsi_2 = 0x2b992ddfa233;
    }
    else
    {
        rax_4 = !(rsi_2);
    }
    __security_cookie = rsi_2;
    __security_cookie_complement = rax_4;
}

void __report_gsfailure(long long unsigned int StackCookie) __noreturn
{
    int64_t rsi;
    int64_t var_10 = rsi;
    RtlCaptureContext(&GS_ContextRecord);
    uint64_t Rip_1 = GS_ContextRecord.Rip;
    uint64_t ImageBase;
    IMAGE_RUNTIME_FUNCTION_ENTRY* FunctionEntry = RtlLookupFunctionEntry(Rip_1, &ImageBase, nullptr);
    void EstablisherFrame;
    void HandlerData;
    if (FunctionEntry == 0)
    {
        GS_ContextRecord.Rip = __return_addr;
        GS_ContextRecord.Rsp = &var_10;
    }
    else
    {
        RtlVirtualUnwind(UNW_FLAG_NHANDLER, ImageBase, Rip_1, FunctionEntry, &GS_ContextRecord, &HandlerData, &EstablisherFrame, nullptr);
    }
    uint64_t Rip = GS_ContextRecord.Rip;
    GS_ContextRecord.Rcx = StackCookie;
    GS_ExceptionRecord.ExceptionCode = 0xc0000409;
    GS_ExceptionRecord.ExceptionFlags = 1;
    GS_ExceptionRecord.ExceptionAddress = Rip;
    long long unsigned int __security_cookie_1 = __security_cookie;
    long long unsigned int __security_cookie_complement_1 = __security_cookie_complement;
    SetUnhandledExceptionFilter(nullptr);
    UnhandledExceptionFilter(&GS_ExceptionPointers);
    TerminateProcess(GetCurrentProcess(), 0xc0000409);
    abort();
    /* no return */
}

int __dyn_tls_dtor(void* hDllHandle, long unsigned int dwReason, void* lpreserved)
{
    if ((dwReason != 0 && dwReason != 3))
    {
        return 1;
    }
    __mingw_TLScallback(hDllHandle, dwReason, lpreserved);
    return 1;
}

int __dyn_tls_init(void* hDllHandle, long unsigned int dwReason, void* lpreserved)
{
    if (_CRT_MT != 2)
    {
        _CRT_MT = 2;
    }
    if (dwReason == 2)
    {
        /* nop */
    }
    else if (dwReason == 1)
    {
        __mingw_TLScallback(hDllHandle, dwReason, lpreserved);
    }
    return 1;
}

int __tlregdtor(void (* func)()) __pure
{
    return 0;
}

_onexit_t_1 mingw_onexit(int (* func)())
{
    void* pbegin_1 = _decode_pointer(__onexitbegin);
    void* pbegin = pbegin_1;
    if (pbegin_1 == -1)
    {
        return _onexit(func);
    }
    _lock(8);
    void* pbegin_2 = _decode_pointer(__onexitbegin);
    void (** __onexitend_1)() = __onexitend;
    pbegin = pbegin_2;
    void* pend = _decode_pointer(__onexitend_1);
    _onexit_t_1 rax_1 = __dllonexit(func, &pbegin, &pend);
    void* rax_2 = _encode_pointer(pbegin);
    void* pend_1 = pend;
    __onexitbegin = rax_2;
    __onexitend = _encode_pointer(pend_1);
    _unlock(8);
    return rax_1;
}

uint64_t atexit(void (* func)())
{
    _onexit_t_1 rax;
    rax = mingw_onexit(func) == 0;
    return -(rax);
}

int32_t my_lconv_init()
{
    /* tailcall */
    return __lconv_init();
}

int64_t _ValidateImageBase.part.0(void* arg1)
{
    void* rcx = (arg1 + *(arg1 + 0x3c));
    if (*rcx == 0x4550)
    {
        int64_t rax_1;
        rax_1 = *(rcx + 0x18) == 0x20b;
        return rax_1;
    }
    return 0;
}

int _ValidateImageBase(unsigned char* pImageBase)
{
    if (*pImageBase == 0x5a4d)
    {
        /* tailcall */
        return _ValidateImageBase.part.0(pImageBase);
    }
    return 0;
}

void* _FindPESection(unsigned char* pImageBase, long long unsigned int rva)
{
    void* rcx = &pImageBase[*(pImageBase + 0x3c)];
    void* rax_1 = ((rcx + *(rcx + 0x14)) + 0x18);
    uint32_t rcx_1 = *(rcx + 6);
    if (rcx_1 != 0)
    {
        void* r9_1 = ((rax_1 + ((rcx_1 - 1) * 0x28)) + 0x28);
        do
        {
            uint64_t r8_1 = *(rax_1 + 0xc);
            if ((r8_1 <= rva && rva < (r8_1 + *(rax_1 + 8))))
            {
                return rax_1;
            }
            rax_1 = (rax_1 + 0x28);
        } while (rax_1 != r9_1);
    }
    return nullptr;
}

char* _FindPESectionByName(char const* pName)
{
    if (strlen(pName) <= 8)
    {
        if (_ValidateImageBase.part.0(&__dos_header) == 0)
        {
            return 0;
        }
        char* _Str1 = &__section_headers;
        do
        {
            if (strncmp(_Str1, pName, 8) == 0)
            {
                return _Str1;
            }
            _Str1 = &_Str1[0x28];
        } while (_Str1 != 0x400430);
    }
    return 0;
}

struct _IMAGE_SECTION_HEADER* __mingw_GetSectionForAddress(void* p)
{
    if (_ValidateImageBase.part.0(&__dos_header) != 0)
    {
        /* tailcall */
        return _FindPESection(&__dos_header, (p - 0x400000));
    }
    return 0;
}

int __mingw_GetSectionCount()
{
    int32_t rax = _ValidateImageBase.part.0(&__dos_header);
    if (rax != 0)
    {
        return 0x11;
    }
    return rax;
}

void* _FindPESectionExec(long long unsigned int eNo)
{
    long long unsigned int eNo_1 = eNo;
    if (_ValidateImageBase.part.0(&__dos_header) == 0)
    {
        return 0;
    }
    void* i = &__section_headers;
    do
    {
        if ((*(i + 0x27) & 0x20) != 0)
        {
            if (eNo_1 == 0)
            {
                return i;
            }
            eNo_1 = (eNo_1 - 1);
        }
        i = (i + 0x28);
    } while (i != 0x400430);
    return 0;
}

unsigned char* _GetPEImageBase()
{
    int64_t rbx = 0;
    if (_ValidateImageBase.part.0(&__dos_header) != 0)
    {
        rbx = 0x400000;
    }
    return rbx;
}

int _IsNonwritableInCurrentImage(unsigned char* pTarget)
{
    int32_t rax = _ValidateImageBase.part.0(&__dos_header);
    if (rax != 0)
    {
        void* rax_1 = _FindPESection(&__dos_header, (pTarget - 0x400000));
        if (rax_1 != 0)
        {
            return (!(*(rax_1 + 0x24)) >> 0x1f);
        }
        rax = 0;
    }
    return rax;
}

char const* __mingw_enum_import_library_names(int i)
{
    int i_1 = i;
    if ((_ValidateImageBase.part.0(&__dos_header) != 0 && _FindPESection(&__dos_header, 0x9000) != 0))
    {
        void* rdx_1 = &_.idata$2;
        while (true)
        {
            if ((*(rdx_1 + 4) == 0 && *(rdx_1 + 0xc) == 0))
            {
                return 0;
            }
            if (i_1 <= 0)
            {
                break;
            }
            i_1 = (i_1 - 1);
            rdx_1 = (rdx_1 + 0x14);
        }
        return (*(rdx_1 + 0xc) + 0x400000);
    }
    return 0;
}

void __mingwthr_run_key_dtors()
{
    EnterCriticalSection(&__mingwthr_cs);
    struct __mingwthr_key* i = key_dtor_list;
    if (i != 0)
    {
        do
        {
            int64_t rax_1 = TlsGetValue(i->key);
            if ((GetLastError() == NO_ERROR && rax_1 != 0))
            {
                i->dtor();
            }
            i = i->next;
        } while (i != 0);
    }
    /* tailcall */
    return LeaveCriticalSection(&__mingwthr_cs);
}

int volatile ___w64_mingwthr_add_key_dtor(long unsigned int key, void (* dtor)())
{
    int volatile __mingwthr_cs_init_1 = __mingwthr_cs_init;
    if (__mingwthr_cs_init_1 != 0)
    {
        long unsigned int* rax = calloc(1, 0x18);
        if (rax != 0)
        {
            *rax = key;
            *(rax + 8) = dtor;
            EnterCriticalSection(&__mingwthr_cs);
            struct __mingwthr_key* key_dtor_list_1 = key_dtor_list;
            key_dtor_list = rax;
            *(rax + 0x10) = key_dtor_list_1;
            LeaveCriticalSection(&__mingwthr_cs);
            return 0;
        }
        __mingwthr_cs_init_1 = -1;
    }
    return __mingwthr_cs_init_1;
}

int ___w64_mingwthr_remove_key_dtor(long unsigned int key)
{
    if (__mingwthr_cs_init == 0)
    {
        return 0;
    }
    EnterCriticalSection(&__mingwthr_cs);
    struct __mingwthr_key* key_dtor_list_1 = key_dtor_list;
    struct __mingwthr_key* next;
    struct __mingwthr_key* rcx;
    if (key_dtor_list_1 != 0)
    {
        if (key_dtor_list_1->key == key)
        {
            rcx = key_dtor_list_1;
            key_dtor_list = key_dtor_list_1->next;
        }
        else
        {
            while (true)
            {
                next = key_dtor_list_1->next;
                if (next == 0)
                {
                    break;
                }
                if (next->key == key)
                {
                    break;
                }
                key_dtor_list_1 = next;
            }
        }
    }
    if ((key_dtor_list_1 == 0 || ((key_dtor_list_1 != 0 && key_dtor_list_1->key != key) && next == 0)))
    {
        LeaveCriticalSection(&__mingwthr_cs);
    }
    if (key_dtor_list_1 != 0)
    {
        if ((key_dtor_list_1->key != key && next != 0))
        {
            rcx = next;
            key_dtor_list_1->next = next->next;
        }
        if ((key_dtor_list_1->key == key || (key_dtor_list_1->key != key && next != 0)))
        {
            free(rcx);
            LeaveCriticalSection(&__mingwthr_cs);
        }
    }
    return 0;
}

int __mingw_TLScallback(void* hDllHandle, long unsigned int reason, void* reserved)
{
    if (reason == 1)
    {
        if (__mingwthr_cs_init == 0)
        {
            InitializeCriticalSection(&__mingwthr_cs);
        }
        __mingwthr_cs_init = 1;
        return 1;
    }
    if (reason < 1)
    {
        if (__mingwthr_cs_init != 0)
        {
            __mingwthr_run_key_dtors();
        }
        if (__mingwthr_cs_init == 1)
        {
            __mingwthr_cs_init = 0;
            DeleteCriticalSection(&__mingwthr_cs);
        }
    }
    else if ((reason == 3 && __mingwthr_cs_init != 0))
    {
        __mingwthr_run_key_dtors();
    }
    return 1;
}

int64_t _.text(int64_t arg1 @ rax)
{
    int64_t var_10 = arg1;
    void* rcx = &arg_8;
    if (arg1 >= 0x1000)
    {
        do
        {
            rcx = (rcx - 0x1000);
            *rcx = *rcx;
            arg1 = (arg1 - 0x1000);
        } while (arg1 > 0x1000);
    }
    void* rcx_1 = (rcx - arg1);
    *rcx_1 = *rcx_1;
    return var_10;
}

EXCEPTION_DISPOSITION _.text(struct _EXCEPTION_RECORD* ExceptionRecord, void* EstablisherFrame, struct _CONTEXT* ContextRecord, struct _DISPATCHER_CONTEXT* DispatcherContext)
{
    /* tailcall */
    return __C_specific_handler(ExceptionRecord, EstablisherFrame, ContextRecord, DispatcherContext);
}

void __set_app_type(enum _crt_app_type _Type)
{
    /* tailcall */
    return __set_app_type(_Type);
}

uint64_t __getmainargs(int32_t* arg1, int64_t* arg2, int64_t* arg3, int32_t arg4, int32_t* arg5)
{
    /* tailcall */
    return __getmainargs(arg1, arg2, arg3, arg4, arg5);
}

void (*)() mingw_get_invalid_parameter_handler()
{
    return handler;
}

void (*)() mingw_set_invalid_parameter_handler(void (* new_handler)())
{
    void (* handler_1)() = handler;
    handler = new_handler;
    return handler_1;
}

int64_t malloc(uint64_t _Size)
{
    /* tailcall */
    return malloc(_Size);
}

uint64_t strlen(char const* _Str)
{
    /* tailcall */
    return strlen(_Str);
}

int64_t memcpy(void* _Dst, void const* _Src, uint64_t _Size)
{
    /* tailcall */
    return memcpy(_Dst, _Src, _Size);
}

void _cexit()
{
    /* tailcall */
    return _cexit();
}

void _amsg_exit(int32_t rterrnum)
{
    /* tailcall */
    return _amsg_exit(rterrnum);
}

void _initterm(_PVFV* _First, _PVFV* _Last)
{
    /* tailcall */
    return _initterm(_First, _Last);
}

void exit(int32_t _Except) __noreturn
{
    /* tailcall */
    return exit(_Except);
}

int32_t printf(char const* const _Format, ...)
{
    /* tailcall */
    return printf();
}

int32_t scanf(char const* const _Format, ...)
{
    /* tailcall */
    return scanf();
}

int32_t puts(char const* _Buffer)
{
    /* tailcall */
    return puts(_Buffer);
}

char* _strdup(char const* _Source)
{
    /* tailcall */
    return _strdup(_Source);
}

int32_t getchar()
{
    /* tailcall */
    return getchar();
}

int32_t putchar(int32_t _Character)
{
    /* tailcall */
    return putchar(_Character);
}

void __setusermatherr(_UserMathErrorFunctionPointer _UserMathErrorFunction)
{
    /* tailcall */
    return __setusermatherr(_UserMathErrorFunction);
}

FILE* __iob_func()
{
    /* tailcall */
    return __iob_func();
}

int32_t fprintf(FILE* const _Stream, char const* const _Format, ...)
{
    /* tailcall */
    return fprintf();
}

uint64_t fwrite(void const* _Buffer, uint64_t _ElementSize, uint64_t _ElementCount, FILE* _Stream)
{
    /* tailcall */
    return fwrite(_Buffer, _ElementSize, _ElementCount, _Stream);
}

int32_t vfprintf(FILE* const _Stream, char const* const _Format, va_list _ArgList)
{
    /* tailcall */
    return vfprintf(_Stream, _Format, _ArgList);
}

void abort() __noreturn
{
    /* tailcall */
    return abort();
}

_crt_signal_t signal(int32_t _Signal, _crt_signal_t _Function)
{
    /* tailcall */
    return signal(_Signal, _Function);
}

void _lock(int32_t locknum)
{
    /* tailcall */
    return _lock(locknum);
}

_onexit_t_1 __dllonexit(_onexit_t_1 func, _PVFV** pbegin, _PVFV** pend)
{
    /* tailcall */
    return __dllonexit(func, pbegin, pend);
}

void _unlock(int32_t locknum)
{
    /* tailcall */
    return _unlock(locknum);
}

_onexit_t_1 _.text(_onexit_t_1 _Func)
{
    /* tailcall */
    return _onexit(_Func);
}

int32_t _.text()
{
    /* tailcall */
    return __lconv_init();
}

int32_t strncmp(char const* _Str1, char const* _Str2, uint64_t _MaxCount)
{
    /* tailcall */
    return strncmp(_Str1, _Str2, _MaxCount);
}

int64_t calloc(uint64_t _Count, uint64_t _Size)
{
    /* tailcall */
    return calloc(_Count, _Size);
}

void free(void* _Block)
{
    /* tailcall */
    return free(_Block);
}

void Sleep(uint32_t dwMilliseconds)
{
    /* tailcall */
    return Sleep(dwMilliseconds);
}

LPTOP_LEVEL_EXCEPTION_FILTER SetUnhandledExceptionFilter(LPTOP_LEVEL_EXCEPTION_FILTER lpTopLevelExceptionFilter)
{
    /* tailcall */
    return SetUnhandledExceptionFilter(lpTopLevelExceptionFilter);
}

void GetStartupInfoA(STARTUPINFOA* lpStartupInfo)
{
    /* tailcall */
    return GetStartupInfoA(lpStartupInfo);
}

uint64_t VirtualQuery(void* lpAddress, MEMORY_BASIC_INFORMATION* lpBuffer, uint64_t dwLength)
{
    /* tailcall */
    return VirtualQuery(lpAddress, lpBuffer, dwLength);
}

BOOL VirtualProtect(void* lpAddress, uint64_t dwSize, enum PAGE_PROTECTION_FLAGS flNewProtect, enum PAGE_PROTECTION_FLAGS* lpflOldProtect)
{
    /* tailcall */
    return VirtualProtect(lpAddress, dwSize, flNewProtect, lpflOldProtect);
}

enum WIN32_ERROR GetLastError()
{
    /* tailcall */
    return GetLastError();
}

BOOLEAN RtlAddFunctionTable(IMAGE_RUNTIME_FUNCTION_ENTRY* FunctionTable, uint32_t EntryCount, uint64_t BaseAddress)
{
    /* tailcall */
    return RtlAddFunctionTable(FunctionTable, EntryCount, BaseAddress);
}

void GetSystemTimeAsFileTime(FILETIME* lpSystemTimeAsFileTime)
{
    /* tailcall */
    return GetSystemTimeAsFileTime(lpSystemTimeAsFileTime);
}

uint32_t GetCurrentProcessId()
{
    /* tailcall */
    return GetCurrentProcessId();
}

uint32_t GetCurrentThreadId()
{
    /* tailcall */
    return GetCurrentThreadId();
}

uint32_t GetTickCount()
{
    /* tailcall */
    return GetTickCount();
}

BOOL QueryPerformanceCounter(int64_t* lpPerformanceCount)
{
    /* tailcall */
    return QueryPerformanceCounter(lpPerformanceCount);
}

void RtlCaptureContext(CONTEXT* ContextRecord)
{
    /* tailcall */
    return RtlCaptureContext(ContextRecord);
}

IMAGE_RUNTIME_FUNCTION_ENTRY* RtlLookupFunctionEntry(uint64_t ControlPc, uint64_t* ImageBase, UNWIND_HISTORY_TABLE* HistoryTable)
{
    /* tailcall */
    return RtlLookupFunctionEntry(ControlPc, ImageBase, HistoryTable);
}

EXCEPTION_ROUTINE RtlVirtualUnwind(enum RTL_VIRTUAL_UNWIND_HANDLER_TYPE HandlerType, uint64_t ImageBase, uint64_t ControlPc, IMAGE_RUNTIME_FUNCTION_ENTRY* FunctionEntry, CONTEXT* ContextRecord, void** HandlerData, uint64_t* EstablisherFrame, KNONVOLATILE_CONTEXT_POINTERS* ContextPointers)
{
    /* tailcall */
    return RtlVirtualUnwind(HandlerType, ImageBase, ControlPc, FunctionEntry, ContextRecord, HandlerData, EstablisherFrame, ContextPointers);
}

int32_t UnhandledExceptionFilter(EXCEPTION_POINTERS* ExceptionInfo)
{
    /* tailcall */
    return UnhandledExceptionFilter(ExceptionInfo);
}

HANDLE GetCurrentProcess()
{
    /* tailcall */
    return GetCurrentProcess();
}

BOOL TerminateProcess(HANDLE hProcess, uint32_t uExitCode)
{
    /* tailcall */
    return TerminateProcess(hProcess, uExitCode);
}

void EnterCriticalSection(CRITICAL_SECTION* lpCriticalSection)
{
    /* tailcall */
    return EnterCriticalSection(lpCriticalSection);
}

int64_t TlsGetValue(uint32_t dwTlsIndex)
{
    /* tailcall */
    return TlsGetValue(dwTlsIndex);
}

void LeaveCriticalSection(CRITICAL_SECTION* lpCriticalSection)
{
    /* tailcall */
    return LeaveCriticalSection(lpCriticalSection);
}

void DeleteCriticalSection(CRITICAL_SECTION* lpCriticalSection)
{
    /* tailcall */
    return DeleteCriticalSection(lpCriticalSection);
}

void InitializeCriticalSection(CRITICAL_SECTION* lpCriticalSection)
{
    /* tailcall */
    return InitializeCriticalSection(lpCriticalSection);
}

