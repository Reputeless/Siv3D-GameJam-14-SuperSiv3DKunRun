# include <Siv3D.hpp>
# include <HamFramework.hpp>

// WebP 形式の画像を Base64 化
const String imageBase64 = L"UklGRsgBAABXRUJQVlA4TLsBAAAvL8AHELegKJLUaFEAfhCBdhxsFNzXLzYUtG0jtQw2hmP6ILkyWBGckNS2mociBgnoQhBC4zYJameK+Q8A+PxcsgKNWkfn19z0VuHQ9zRdmYMqVIkzd9qBc6inRIOGRQDEyHbjNtQt44sCDDvqv1biEOVJARH9Z+C2baO4txfb3ivKfwy17ER9nB4PuSzLcieiXo+nOJEdpZwHHgMtHrAnnOeeJXbgCJwHnqMa6AjdrsZHS5+HABxHZaIKCikW5k4PmFEbqFam3GOt34NqHBDYgl94wP6+dVs3ZpQAeuCx8GucZRUZZ3rgyTcyDpO0DFPuQafHFn3Ns7bMc0mrz1PYFn2/m8belHnQ7WlRl2FQLT/wFPa5rnZfznnggd0DXOCSp9vDCBEgFyH33C+079SSN049aVNVsPPs5tHosdOJ56aEEX9+SFb2lviXpxyRvC5JQFAV9BQzp1WypYpkJamH2V9i8M2TvR4iA/2FpPxeTyXXgc/n+7Xztdawf+fx1wrCcrmBEZV6nia68YhIfA8FThh3W86bRdX44WkQjHOeofMlLLbnxvYUG5dTk9HxI55U8fthz0CuqqsHAQA=";

// Opus 形式のサウンドを Base64 化 
const String soundBase64 = L"T2dnUwACAAAAAAAAAAApAAAAAAAAAELihyIBE09wdXNIZWFkAQI4AYC7AAAAAABPZ2dTAAAAAAAAAAAAACkAAAABAAAAu4pZrgE7T3B1c1RhZ3MNAAAAbGlib3B1cyAxLjEuMQEAAAAaAAAARU5DT0RFUj1TaXYzRCBKYW51YXJ5IDIwMTZPZ2dTAARMWwAAAAAAACkAAAACAAAAWzLnFBhZWGaOenhvY2ZpZGdeYl1mZ2ZsY1NNTlf8f/rIxWvgne4XJZf0ooqPVKKfeka/zGscpN9l+xuBo9iMUnNXRMtUkmWbCsTxWilK0tgeV+OdJhCex9I9VrRQoONaYrarsBdVOzwpxgAbeMXzwikwKwPMPPx/0QwPvcg38DK4rq041f69t09YmBcdRSY7GdBuozRRXQ0wfP+FtbHcId1QFfCdwImYHKOwjectyq6cVtZbdn5M34wpQ3p3uBh/l/OektO2ED9VCgDDAXz8imK51KOrsQ10r4iUntAsAv6l9u9H8mgON/szpi6vuvv7SI5orl5z6Rh8Cl+eNDkUy6ZrO5xLP9LJyzXxp9zV9jhVEzC1MeCDvx4CiDWvZww0tl6/TztnhPz0muiAM7o4AAKYHmv8i"
L"AlKL2msuEK3Z08XOznPMhQtNPRNofKEajt8uAgy3FDS93g/hvn8Zovyw8ALNi2WR41/nXwJnmgFqYG3R3/ZTE8M7nNHN2b6DUBrFNl9WypBwuuXJcMizprTDHMYy8E+A0T9Y0VAmUNiPpXTJufpNlkb9V5c5hTlTxdXpxtIGg6nWBNzOi1KX/7ZNuZr/Nb4TKHaQ38ZrHFqCUp0bk/kw0G/pxIKtVJqSfHyor70TeTQSmT+XwAIqfPpYahwYY1uJL6QkLZRqcj/iP4chKuR49EBy/anH3+FvKYEV3tPaATfvmtgwmPeyrJg3f+jgF+ZDYZmInHys03sQe6Z4qYOYkBtb6WN/vn8jiX0FKlOpFygO+a3I0LoSPONghuq8n9j1AM2Fs/Ydi3z7NGXFMYx7MTtupKGKT2epWuQ7H1r81P/5zmA2U9ptgrbZcDgWX0sg/i9+HWD1TltvfLsHh06B5J+asdWLjglBi3mcH6HbINMayNqezEmCos2BNGxOGr8k83OMY1qGgFX9GLssjjo15bANnr4JSl0VJoyEEbHB4fg9hlBLg/gmH2ywZJx0QtLMxcchuc4PmjksLED2Wxu0WiphJj575I3SK72Vo2mFguey15V0DJKX2c5IHrBVZ/3/mMy/HDBE"
L"oyk/tX/h+r8k82K778bn8/f6Sg4eGozqz59zPsugZRXtZF9wpoKbgQP+l9OYmaZCL6fBI1v42qSmwTM8G20zgZtpgLuqk9eQCA4TQ0F3BsAZ7Zg2Exqqd8hWj2s774BEzROmTLv//S25+r8k83Camtpa/E2T6+0MtLKY94Kb2qSLnLhPA4bOAxz6+Ncv7VSnQId3aO6IxT7gOOcPei4vZUfVjMqjzOt3CDiQv5KVFVKJfNoAZ+hvTd9743yRoOAy9D3ceQ14f69GrtJP/nIfWr8k/LTT8ujPHk7cnUQDYZfhBX/cCa30+tRRgl9RhLhlkKV8KTn8XElaRmkijUZa3sZImwZLYfGF7XgE62QRheEEnhYiQaljJ6w01Ace0y8ch1Uijhtd5Xw9a0OE1hO4fivQj4f9UNh9ur8lAP+0DAXZccPP6+EgqzJ2QHXVyTwzWu2/Bdow7ZEgtrDkdS/0YGs979ppy2rPcD36QxrjVNcXs1j91lTfvfPceZfBw44g5pcQC9sIpl/rBsYOBaNqw4juUpCY7i8IB9L5P/q/JPyxt6vlEfqZAVt10oyit/j2B2Hhp67kjIlKrkb2ysRF+lF5wQ1ZIDf3c62RIJqBLGHh16qYR/WNPwVLkz3wxp04SmHkfwQm"
L"Y/ju59rH6Kqmugfzk9PGrTl9cHiawJTtp1q0UAa6vyTzYrvg6W3TRhVdU7iZwvsh4TVuaKvB1fJHxyUXGEcG9yGbryAEEwk2a/CljbwXDD41I4rOi0iLzzgVdpusxAoRqkQH6QY8fFPtnAt/3eIQSWBAHboIS69xbVC7er8k83OMYte47hyHCZXOSsGxkVt3Sv5EKRdRENtqAbTqKcPk+mVQrGusVjoVD+CBcRaj00MZhRjmCnn55BhUlu2UyLcYIPSRwVRNPOGar+fvnck0qEIbHtY+e0V74Y2AYWgavyT8sbpn/nsUSnXLwqS+7HuMjAcAJ8+9yud6y6Li2FpzNDqSGjLSjj45/Q4d78fn+g/fpm4cQCNTLedZSvW2noSf+JN3ishojob/YijGXJ+87v9n9+bIvvJB9WmavyTzc4xi0biQG8E0CxEiJlgGBxM9XyvN/JoK+gAFsaqlStPS/3Pba3VzHjhBEXpO//UthujYFLPctwTXT15AxAiOonKkilvS/qjC4gG9K9JlxspQ0GpBox75J5q8xbVRuT/+Ehk6vyTzdENnzFxTdFiYQDfty7MfxMzptMXRITkeh+CLjYqZRyMk8y5TDIjRIgUAtTAEJRVQ8nbB7GJLk7K32EP/2pWyH+Hk"
L"IwJFy79RD5p130ITFmf66FF9DcC/yjmRrzCWIi9qqJBimr8k83RDZ8NJERnPhOXFsfzQu2b3ZVPMSq0OJpIqnTO01bGRZ/B9LQfsZAMjyzczDOcG/xqYwMwMZMIznwJsTCCVW/aChK6Nm/cX6z2aDKeYoE98U77xyl7esV9WRODyLCA2AZbimr8k/LWj5FtJGtye0Y5fpPljn+JQtO4IEWbrVyi2fgbA6reF+VcY48qpkZBW15K2Z9TGpWg2QqLaj1FGQiPBzVpTX3kj8wEZvRfFWVYSdBLgvLLlRWPGCFqwHKvfhjn0befptLI5SNMir6/5+r8lSksj42n5CS7SriHR24E8yAg4UQL33vkpqGFx9nnzO8UGRsPoE1oNcxl0hvdoV+zBqiSsvJehxXCLRgTyG/Omn4yhBDg+2QEpCLPW3XfF6vXQ+r9tQpRAc8D6ivsC+SWgur8qfgke5Lh+c7xk5Qr32onK3dXfcM06GdZntMwC71m9dHu6hoMbqjGzkhX5oL1qJReCQl3ZV5VnG4pIiI5EH3QCKQMOgq+xhwTcls0dfyJLPM2TfxbZjgIDEVo3zsFGwllUm5xE6Zu+ZD3dNMwqjVga4pmZMOJkule5+wvBj3bsV8bUMsCDex+cDEDpLqNu"
L"vF3XDqF/V5ViHaBjRLskPDA/F7e6LguvglZjjipKpT8S/JOolU2HBxr1qHAs5MVQKh/ErI63hP5gdHXqPaEGPVoozbRALr2NS8Rtm0wA38vJQR05D2tr5piJq3VQwwk/H0NxaUeXM3RVKb+U2+g0AZSV6iVSG/Ub4NXGMti097Y2iz7GVTR0lSIrAqZBeJMTvAQWswGYdpnSQc/nDI4FPu9TJte+fPQOCX48985AT41b/9cDPMb";

void Main()
{
	Window::SetTitle(L"|| SUPER Siv3D-kun RUN || JUMP: [Left Click] or [Space]");
	Window::Resize(512, 384);
	ScalableWindow::Setup(256, 192);
	Graphics::SetBackground(Color(90, 180, 240));
	Graphics2D::SetSamplerState(SamplerState::ClampPoint);

	const Font font(9, L"ＭＳ Ｐゴシック", FontStyle::BitmapBold);
	const Texture texture(Base64::Decode(imageBase64));
	const Sound sound(Base64::Decode(soundBase64));

	int32 y = 0, ya = 0, score = 0, hi = 0, damage = 0;
	PerlinNoise n;
	Array<Rect> walls = { Rect(200, 146, 6, 14), Rect(300, 146, 6, 14), Rect(400, 146, 6, 14) };
	Array<Circle> coins = { Circle(200, 106, 5), Circle(300, 106, 5), Circle(400, 106, 5) };

	while (System::Update())
	{
		{
			const auto transform = ScalableWindow::CreateTransformer();

			const int32 t = System::FrameCount();

			if ((Input::KeySpace | Input::MouseL).clicked && y == 0)
			{
				ya = 15;
			}

			y = Max(y + (ya-- / 2), 0);

			for (auto x : step(256))
			{
				Line(x, 100 - 70 * n.octaveNoise0_1((64 + x + t * 0.2) / 400, 4), x, 160).moveBy(0.5, 0.5).draw(Color(70, 170, 225));
				Line(x, 120 - 60 * n.octaveNoise0_1((x + t * 0.2) / 100, 4), x, 160).moveBy(0.5, 0.5).draw(Color(40, 150, 180));
			}

			for (auto& wall : walls)
			{
				wall.x -= 2;
			}

			for (auto& coin : coins)
			{
				coin.x -= 2;
			}

			if (walls.front().x < -10)
			{
				walls.erase(walls.begin());
				walls.push_back(walls.back().movedBy(Random(80, 240), 0));
			}

			if (coins.front().x < -10)
			{
				coins.erase(coins.begin());
				coins.push_back(coins.back().movedBy(Random(80, 240), 0));
			}

			const Rect player = texture((y == 0 ? t / 7 % 2 : 1) * 24, 0, 24, 32).draw(24, 128 - y);

			for (auto& wall : walls)
			{
				wall.draw(Palette::Red);

				if (wall.intersects(player.stretched(-10, -2)))
				{
					hi = Max(hi, score);
					wall.h = score = 0;
					damage = 60;
				}
			}

			for (auto& coin : coins)
			{
				coin.draw(Palette::Yellow);

				if (coin.intersects(player))
				{
					coin.y = -100;
					++score;
					sound.playMulti();
				}

				if (coin.y == 106 && coin.x <= 16)
				{
					hi = Max(hi, score);
					score = 0;
				}
			}

			Rect(0, 160, 256, 8).draw(Color(40, 180, 80)).stretched(-8, 0, 24, 0).draw(Color(90, 60, 0));

			for (auto i : step(18))
			{
				Rect(i * 16 - t % 16 * 2, 158, 4, 4).draw(Color(40, 190, 80))
					.stretched(i % 2 ? -2 : -1).draw(Color(220, 220, 50))
					.stretched(i % 2 ? 2 : 1).moveBy(0, i % 2 ? 16 : 26).draw(Color(40, 30, 0));
			}

			if (damage)
			{
				Window::BaseClientRect().draw(Alpha(--damage * 3));
			}

			font(score).draw(11, 11, Color(80));
			font(score).draw(10, 10);

			const int32 w = font(L"HI: ", hi).region().w;
			font(L"HI: ", hi).draw(246 - w, 11, Color(80));
			font(L"HI: ", hi).draw(245 - w, 10);
		}

		for (const auto& rect : ScalableWindow::GetBlackBars())
		{
			rect.draw({ Color(80), Color(80), Color(5), Color(5) });
		}
	}
}
