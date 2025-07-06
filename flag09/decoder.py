#%%
import base64

#%%
tokenb64 = 'ZjRrbW02cHw9gn9wgm6DgkRCg0R1e3+MiQo='


# %%
e1=base64.b64decode(tokenb64)


#%%

e2 = []

for num,byte in enumerate(e1):
    e2.append( (byte - num)%256)
# %%

print(''.join(chr(n) for n in e2))
# %%
