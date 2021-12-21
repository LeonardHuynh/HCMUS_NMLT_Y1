// 1.Kiểm tra một số có phải là só chính phương hay không?
bool kiem_tra_so_chinh_phuong(int a)
{
	int can_bac_hai = sqrt(a);
	if (can_bac_hai * can_bac_hai == a)
	{
    return true;
	}
	return false;
}

// 2.Hoán vị 2 số thực:
void hoan_vi(float& a, float& b)
{
	float tg = a;
	a = b;
	b = tg;
}

// 3.Kiểm tra một số có phải là số chẵn? 
bool Ktra_SoChan(int a) { 
  if (a % 2 == 0) { 
    return true; // Nếu kiểm tra số lẻ thì ngược lại
  }
  return false;
}

// 4.Kiểm tra số toàn số lẻ: 
bool KTra_SoToanLe(int n)
{
	bool ket_qua = true;
	while (n != 0)
	{
		if ((n % 10) % 2 == 0)
		{
			ket_qua = false;
			break;
		}
		n /= 10;
	}
	return ket_qua;
}
